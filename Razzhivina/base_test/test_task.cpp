#include "task.h"
#include <gtest.h>

TEST(Task, can_create_task) {
	ASSERT_NO_THROW(Task tTask);
}

TEST(TaskList, can_create_tasklist){
	ASSERT_NO_THROW(TaskList tl);
}

TEST(TaskList, can_add_new_task_in_list){
	TaskList tl;
	Task tmp;
	ASSERT_NO_THROW(tl.AddTask(tmp));
}
