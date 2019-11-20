#include "statistic.h"
#include <gtest.h>

TEST(Statistic, can_add_done_tasks){
	Statistic st;
	ASSERT_NO_THROW(st.AddDone(5));
}

TEST(Statistic, cannot_add_done_with_negative_tasks) {
	Statistic st;
	ASSERT_ANY_THROW(st.AddDone(5));
}

TEST(Statistic, can_count_task_in_queue) {
	Statistic st;
	ASSERT_NO_THROW(st.InQueue(5));
}

TEST(Statistic, cannot_negativ_count_task_in_queue) {
	Statistic st;
	ASSERT_NO_THROW(st.InQueue(-5));
}

TEST(Statistic, can_add_average) {
	Statistic st;
	ASSERT_NO_THROW(st.Average(5));
}

TEST(Statistic, cannot_add_negative_average) {
	Statistic st;
	ASSERT_NO_THROW(st.Average(-5));
}