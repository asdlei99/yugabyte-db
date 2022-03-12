// Copyright (c) YugaByte, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except
// in compliance with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied.  See the License for the specific language governing permissions and limitations
// under the License.
//

#ifndef YB_MASTER_SNAPSHOT_COORDINATOR_CONTEXT_H
#define YB_MASTER_SNAPSHOT_COORDINATOR_CONTEXT_H

#include "yb/common/common_fwd.h"
#include "yb/common/entity_ids.h"
#include "yb/common/snapshot.h"

#include "yb/docdb/docdb_fwd.h"

#include "yb/master/master_fwd.h"
#include "yb/master/master_types.pb.h"

#include "yb/rpc/rpc_fwd.h"

#include "yb/server/server_fwd.h"

#include "yb/tablet/tablet_fwd.h"

#include "yb/tserver/backup.pb.h"

namespace yb {
namespace master {

using TabletSnapshotOperationCallback =
    std::function<void(Result<const tserver::TabletSnapshotOpResponsePB&>)>;

using ScheduleMinRestoreTime =
    std::unordered_map<SnapshotScheduleId, HybridTime, SnapshotScheduleIdHash>;

YB_STRONGLY_TYPED_BOOL(SendMetadata);

// Context class for MasterSnapshotCoordinator.
class SnapshotCoordinatorContext {
 public:
  // Return tablet infos for specified tablet ids.
  // The returned vector is always of the same length as the input vector,
  // with null entries returned for unknown tablet ids.
  virtual TabletInfos GetTabletInfos(const std::vector<TabletId>& id) = 0;

  virtual AsyncTabletSnapshotOpPtr CreateAsyncTabletSnapshotOp(
      const TabletInfoPtr& tablet, const std::string& snapshot_id,
      tserver::TabletSnapshotOpRequestPB::Operation operation,
      TabletSnapshotOperationCallback callback) = 0;

  virtual void ScheduleTabletSnapshotOp(const AsyncTabletSnapshotOpPtr& operation) = 0;

  virtual Result<SysRowEntries> CollectEntriesForSnapshot(
      const google::protobuf::RepeatedPtrField<TableIdentifierPB>& tables) = 0;

  virtual CHECKED_STATUS RestoreSysCatalog(
      SnapshotScheduleRestoration* restoration, tablet::Tablet* tablet,
      Status* complete_status) = 0;
  virtual CHECKED_STATUS VerifyRestoredObjects(const SnapshotScheduleRestoration& restoration) = 0;

  virtual void CleanupHiddenObjects(const ScheduleMinRestoreTime& schedule_min_restore_time) = 0;

  virtual const Schema& schema() = 0;

  virtual void Submit(std::unique_ptr<tablet::Operation> operation, int64_t leader_term) = 0;

  virtual rpc::Scheduler& Scheduler() = 0;

  virtual int64_t LeaderTerm() = 0;

  virtual server::Clock* Clock() = 0;

  virtual Result<size_t> GetNumLiveTServersForActiveCluster() = 0;

  virtual ~SnapshotCoordinatorContext() = default;
};

Result<docdb::KeyBytes> EncodedKey(
    SysRowEntryType type, const Slice& id, SnapshotCoordinatorContext* context);

} // namespace master
} // namespace yb

#endif  // YB_MASTER_SNAPSHOT_COORDINATOR_CONTEXT_H
