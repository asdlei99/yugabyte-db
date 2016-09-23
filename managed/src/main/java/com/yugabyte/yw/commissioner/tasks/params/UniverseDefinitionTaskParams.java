// Copyright (c) YugaByte, Inc.

package com.yugabyte.yw.commissioner.tasks.params;

import java.util.Set;

import com.yugabyte.yw.models.helpers.NodeDetails;
import com.yugabyte.yw.models.helpers.PlacementInfo;
import com.yugabyte.yw.models.helpers.UserIntent;

public class UniverseDefinitionTaskParams extends UniverseTaskParams {
  // This should be a globally unique name - it is a combination of the customer id and the universe
  // id. This is used as the prefix of node names in the universe.
  public String nodePrefix = null;

  // The set of new nodes that need to be created.
  public Set<NodeDetails> newNodesSet = null;

  // The configuration for the universe the user intended.
  public UserIntent userIntent;

  // The placement information computed from the user intent.
  public PlacementInfo placementInfo;

  // The number of nodes to provision.
  public int numNodes;

  // Expected version of the universe for operation execution.
  public int expectedUniverseVersion;

  // The software version of YB to install.
  // TODO: replace with a nicer string as default.
  public String ybServerPkg =
      "yb-server-0.0.1-SNAPSHOT.1ea4847731ee5f6013b5fd3be29ca4ef6bc638cd.tar.gz";
}
