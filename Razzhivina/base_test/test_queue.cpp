#include "queue.h"
#include <gtest.h>

TEST(Queue, can_create_queue_with_positive_lenght) {
	ASSERT_NO_THROW(Queue <int> que(2));
}

TEST(Queue, cannot_create_queue_with_negative_lenght) {
	ASSERT_ANY_THROW(Queue <int> que(-2));
}

TEST(Queue, cannot_create_queue_with_large_lenght) {
	ASSERT_ANY_THROW(Queue <int> que(MAX_QUEUE_SIZE+1));
}

TEST(Queue, full_is_correct){
	Queue<int> que(2);
	EXPECT_EQ(que.isEmpty(), true);
	que.addEnd(1);
	EXPECT_EQ(que.isEmpty(), false);
}

TEST(Queue, empty_is_correct){
	Queue<int> que(2);
	que.addEnd(1);
	que.addEnd(2);
	EXPECT_EQ(que.isFull(), true);
	que.Pop();
	EXPECT_EQ(que.isFull(), false);
}

TEST(Queue, can_push_in_queue_with_free_end) {
	Queue <int> que(5);
	for (int i = 0; i < 5; i++)
		que.addEnd(i);
	que.Pop();
	ASSERT_NO_THROW(que.addEnd(5));
}

TEST(Queue, cannot_add_end_in_full_queue) {
	int i = 5;
	Queue <int> que(i);
	while (i > 0) {
		que.addEnd(i);
		i--;
	}
	ASSERT_ANY_THROW(que.addEnd(5));
}

TEST(Queue, can_pop_and_push_element){
	Queue<int> que(5);
	que.addEnd(5);
	que.addEnd(1);
	EXPECT_EQ(que.Pop(), 5);
	EXPECT_EQ(que.Pop(), 1);
}