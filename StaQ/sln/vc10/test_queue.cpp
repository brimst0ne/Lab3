#include "Queue.h"

#include <gtest.h>

TEST(Queue, can_create_Queue_with_positive_length)
{
	ASSERT_NO_THROW(Queue<int> v(5));
}

TEST(Queue, can_create_Queue_with_zero_size)
{
	ASSERT_NO_THROW(Queue<int> v(0));
}

TEST(Queue, throws_when_creates_Queue_with_negative_length)
{
	ASSERT_ANY_THROW(Queue<int> v(-5));
}

TEST(Queue, IsFull)
{
	Queue<int>q(1);
	int m = 2;
	q.PushElem(m);
	EXPECT_EQ(q.IsFull(), 1);
}

TEST(Queue, IsEmpty)
{
	Queue<int>q(1);
	int m = 2;
	q.PushElem(m);
	q.PopElem();
	EXPECT_EQ(q.IsEmpty(), 1);
}

TEST(Queue, can_copy_Queue)
{
	Queue<int> v(10);

	ASSERT_NO_THROW(Queue<int> v1(v));
}

TEST(Queue, copied_Queue_has_its_own_memory)
{
	Queue<int>A(5);
	Queue<int>B(A);
	EXPECT_NE(A.GetMemory(), B.GetMemory());
}

TEST(Queue, can_get_size)
{
	Queue<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(Queue, can_get_start_index)
{
	Queue<int> v(4);

	EXPECT_EQ(0, v.GetFirstElem());
}

TEST(Queue, push_and_pop_element)
{
	Queue<int>A(5);
	int a[6];
	for (int i = 0; i < 6; i++)
	{
		a[i] = 4 * i;
	}
	for (int i = A.GetFirstElem(); i < A.GetSize(); i++)
	{
		A.PushElem(a[i]);
	}
	EXPECT_EQ(A.PopElem(), 0);
}
TEST(Queue, find_element_in_nonexisting_Queue)
{
	Stack<int>a;
	ASSERT_ANY_THROW(a.FindElem(1));
}

TEST(Queue, find_element_in_empty_Queue)
{
	Queue<int>a(1);
	int b = 2;
	a.PushElem(b);
	a.PopElem();
	ASSERT_ANY_THROW(a.FindElem(2));
}
TEST(Queue, find_elem_in_Queue)
{
	Queue<int>a(2);
	int b = 2;
	int c = 3;
	a.PushElem(b);
	a.PushElem(c);
	EXPECT_EQ(a.FindElem(1), 0);
}
TEST(Queue, find_elem_in_Queue_2)
{
	Queue<int>a(2);
	int b = 2;
	int c = 3;
	a.PushElem(b);
	a.PushElem(c);
	EXPECT_EQ(a.FindElem(2), 1);
}
TEST(Queue, min_elem_in_Queue)
{
	Queue<int>a(2);
	int b = 2;
	int c = 3;
	a.PushElem(b);
	a.PushElem(c);
	EXPECT_EQ(a.MinElem(), 2);
}
TEST(Queue, min_elem_in_empty_Queue)
{
	Queue<int>a;
	ASSERT_ANY_THROW(a.MinElem());
}
