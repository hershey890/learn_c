#include "../linked_list/hj_list.h"
#include <gtest/gtest.h>

TEST(LinkedListTest, Init) {
    struct hj_list lst;
    hj_list_init(&lst);
    ASSERT_EQ(lst.size, 0);
    // ASSERT_EQ(lst.front, NULL);
    // ASSERT_EQ(lst.back, NULL);
}

TEST(LinkedListTest, PushFront) {
    int data[] = {1,2,3};

    // hj_list lst;
    // hj_list_init(&lst);
    // hj_list_push_front(&lst, &data[0]);
    // EXPECT_EQ(lst.size, 1);
    // EXPECT_EQ(lst.front->data, data[0]);
    // EXPECT_EQ(lst.back->data, data[0]);
    // hj_list_push_front(&lst, &data[1]);
    // EXPECT_EQ(lst.size, 2);
    // EXPECT_EQ(lst.front->data, data[1]);
    // EXPECT_EQ(lst.back->data, data[0]);
    // hj_list_push_front(&lst, &data[2]);
    // EXPECT_EQ(lst.size, 3);
    // EXPECT_EQ(lst.front->data, data[2]);
    // EXPECT_EQ(lst.back->data, data[0]);

    // hj_node* node = lst.front;
    // for(int i=0; node; i++, node = node->next)
    //     EXPECT_EQ(node->data, data[i]);

    // hj_list_clear(&lst);
}

TEST(LinkedListTest, PushBack) {

}

TEST(LinkedListTest, PopFront) {

}

TEST(LinkedListTest, PopBack) {

}

TEST(LinkedListTest, Clear) {

}