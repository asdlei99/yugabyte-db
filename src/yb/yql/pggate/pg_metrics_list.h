//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------

#pragma once

#ifdef __cplusplus

namespace yb::pggate {

#endif // __cplusplus

typedef enum PgAnalyzeMetrics {
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_MISS,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_HIT,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_ADD,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_ADD_FAILURES,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_INDEX_MISS,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_INDEX_HIT,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_FILTER_MISS,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_FILTER_HIT,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_DATA_MISS,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_DATA_HIT,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_BYTES_READ,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_BYTES_WRITE,
    YB_ANALYZE_METRIC_ROCKSDB_BLOOM_FILTER_USEFUL,
    YB_ANALYZE_METRIC_ROCKSDB_BLOOM_FILTER_CHECKED,
    YB_ANALYZE_METRIC_ROCKSDB_MEMTABLE_HIT,
    YB_ANALYZE_METRIC_ROCKSDB_MEMTABLE_MISS,
    YB_ANALYZE_METRIC_ROCKSDB_GET_HIT_L0,
    YB_ANALYZE_METRIC_ROCKSDB_GET_HIT_L1,
    YB_ANALYZE_METRIC_ROCKSDB_GET_HIT_L2_AND_UP,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_KEYS_WRITTEN,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_KEYS_READ,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_KEYS_UPDATED,
    YB_ANALYZE_METRIC_ROCKSDB_BYTES_WRITTEN,
    YB_ANALYZE_METRIC_ROCKSDB_BYTES_READ,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_DB_SEEK,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_DB_NEXT,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_DB_PREV,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_DB_SEEK_FOUND,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_DB_NEXT_FOUND,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_DB_PREV_FOUND,
    YB_ANALYZE_METRIC_ROCKSDB_ITER_BYTES_READ,
    YB_ANALYZE_METRIC_ROCKSDB_NO_FILE_CLOSES,
    YB_ANALYZE_METRIC_ROCKSDB_NO_FILE_OPENS,
    YB_ANALYZE_METRIC_ROCKSDB_NO_FILE_ERRORS,
    YB_ANALYZE_METRIC_ROCKSDB_STALL_L0_SLOWDOWN_MICROS,
    YB_ANALYZE_METRIC_ROCKSDB_STALL_MEMTABLE_COMPACTION_MICROS,
    YB_ANALYZE_METRIC_ROCKSDB_STALL_L0_NUM_FILES_MICROS,
    YB_ANALYZE_METRIC_ROCKSDB_STALL_MICROS,
    YB_ANALYZE_METRIC_ROCKSDB_DB_MUTEX_WAIT_MICROS,
    YB_ANALYZE_METRIC_ROCKSDB_RATE_LIMIT_DELAY_MILLIS,
    YB_ANALYZE_METRIC_ROCKSDB_NO_ITERATORS,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_MULTIGET_CALLS,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_MULTIGET_KEYS_READ,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_MULTIGET_BYTES_READ,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_FILTERED_DELETES,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_MERGE_FAILURES,
    YB_ANALYZE_METRIC_ROCKSDB_SEQUENCE_NUMBER,
    YB_ANALYZE_METRIC_ROCKSDB_BLOOM_FILTER_PREFIX_CHECKED,
    YB_ANALYZE_METRIC_ROCKSDB_BLOOM_FILTER_PREFIX_USEFUL,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_OF_RESEEKS_IN_ITERATION,
    YB_ANALYZE_METRIC_ROCKSDB_GET_UPDATES_SINCE_CALLS,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_COMPRESSED_MISS,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_COMPRESSED_HIT,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_COMPRESSED_ADD,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_COMPRESSED_ADD_FAILURES,
    YB_ANALYZE_METRIC_ROCKSDB_WAL_FILE_SYNCED,
    YB_ANALYZE_METRIC_ROCKSDB_WAL_FILE_BYTES,
    YB_ANALYZE_METRIC_ROCKSDB_WRITE_DONE_BY_SELF,
    YB_ANALYZE_METRIC_ROCKSDB_WRITE_DONE_BY_OTHER,
    YB_ANALYZE_METRIC_ROCKSDB_WRITE_WITH_WAL,
    YB_ANALYZE_METRIC_ROCKSDB_COMPACT_READ_BYTES,
    YB_ANALYZE_METRIC_ROCKSDB_COMPACT_WRITE_BYTES,
    YB_ANALYZE_METRIC_ROCKSDB_FLUSH_WRITE_BYTES,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_DIRECT_LOAD_TABLE_PROPERTIES,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_SUPERVERSION_ACQUIRES,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_SUPERVERSION_RELEASES,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_SUPERVERSION_CLEANUPS,
    YB_ANALYZE_METRIC_ROCKSDB_NUMBER_BLOCK_NOT_COMPRESSED,
    YB_ANALYZE_METRIC_ROCKSDB_MERGE_OPERATION_TOTAL_TIME,
    YB_ANALYZE_METRIC_ROCKSDB_FILTER_OPERATION_TOTAL_TIME,
    YB_ANALYZE_METRIC_ROCKSDB_ROW_CACHE_HIT,
    YB_ANALYZE_METRIC_ROCKSDB_ROW_CACHE_MISS,
    YB_ANALYZE_METRIC_ROCKSDB_NO_TABLE_CACHE_ITERATORS,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_SINGLE_TOUCH_HIT,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_SINGLE_TOUCH_ADD,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_SINGLE_TOUCH_BYTES_READ,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_SINGLE_TOUCH_BYTES_WRITE,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_MULTI_TOUCH_HIT,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_MULTI_TOUCH_ADD,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_MULTI_TOUCH_BYTES_READ,
    YB_ANALYZE_METRIC_ROCKSDB_BLOCK_CACHE_MULTI_TOUCH_BYTES_WRITE,

    YB_ANALYZE_METRIC_COUNT,
} YbPgAnalyzeMetrics;

#ifdef __cplusplus

} // namespace yb::pggate

#endif // __cplusplus
