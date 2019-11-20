#include "cluster.h"
#include <gtest.h>

TEST(Cluster, can_create_cluster){
	ASSERT_NO_THROW(cluster cl(5));
}

TEST(cluster, cannot_create_cluster_with_negative_count_of_processors){
	ASSERT_ANY_THROW(Cluster cl(-5));
}

TEST(Cluster, can_Start_Cluster){
	Cluster cl(5);
	ASSERT_NO_THROW(cl.StartCluster(5));
}

TEST(Cluster, cannot_Start_Cluster){
	Cluster cl(5);
	ASSERT_ANY_THROW(cl.StartCluster(-5));
}