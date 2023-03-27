#include "err_codes.h"
#include <check.h>
#include "list.h"
#include <stdio.h>

int int_cmp(const void *ptr1, const void *ptr2)
{
    return *(int *)ptr1 - *(int *)ptr2;
}

// ###############################################
//         start find_suite
// ###############################################
START_TEST(test_find_empty)
{
    int data = 1;
    node_t *tmp = node_create(&data);
    if (tmp == NULL)
        ck_assert_int_eq(1, 0);
    ck_assert_ptr_eq(find(NULL, &data, &int_cmp), NULL);
    del_node(tmp);
}
END_TEST

START_TEST(test_find_found)
{
    int data = 1;
    node_t *tmp = node_create(&data);
    if (tmp == NULL)
        ck_assert_int_eq(1, 0);
    ck_assert_ptr_eq(find(tmp, &data, &int_cmp), tmp);
    del_node(tmp);
}
END_TEST

START_TEST(test_find_incorrect_key)
{
    int data = 1;
    node_t *tmp = node_create(&data);
    if (tmp == NULL)
        ck_assert_int_eq(1, 0);
    ck_assert_ptr_eq(find(tmp, NULL, &int_cmp), NULL);
    del_node(tmp);
}
END_TEST

START_TEST(test_find_not_found)
{
    int data = 1;
    int key = 2;
    node_t *tmp = node_create(&data);
    if (tmp == NULL)
        ck_assert_int_eq(1, 0);
    ck_assert_ptr_eq(find(NULL, &key, &int_cmp), NULL);
    del_node(tmp);
}
END_TEST

Suite *find_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;

    s = suite_create("find suite");

    pos = tcase_create("pos");
    tcase_add_test(pos, test_find_found);

    neg = tcase_create("neg");
    tcase_add_test(neg, test_find_not_found);
    tcase_add_test(neg, test_find_empty);
    tcase_add_test(neg, test_find_incorrect_key);

    suite_add_tcase(s, pos);
    suite_add_tcase(s, neg);

    return s;
}

// ###############################################
//         end find_suite
// ###############################################

// ###############################################
//         start pop_front
// ###############################################

START_TEST(test_pop_front_empty)
{
    ck_assert_ptr_eq(pop_front(NULL), NULL);
}
END_TEST

START_TEST(test_pop_front_single_elem)
{
    int data = 1;
    node_t *tmp = node_create(&data);
    if (tmp == NULL)
        ck_assert_int_eq(1, 0);
    ck_assert_ptr_eq(pop_front(&tmp), &data);
    ck_assert_ptr_eq(tmp, NULL);
}
END_TEST

START_TEST(test_pop_front_many_elems)
{
    int data = 1;
    node_t *tmp1 = node_create(&data);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);
    node_t *tmp2 = node_create(&data);
    if (tmp2 == NULL)
        ck_assert_int_eq(1, 0);
    tmp1->next = tmp2;
    ck_assert_ptr_eq(pop_front(&tmp1), &data);
    ck_assert_ptr_eq(tmp1, tmp2);
    del_node(tmp2);
}
END_TEST

Suite *pop_front_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;

    s = suite_create("pop_front suite");

    pos = tcase_create("pos");
    tcase_add_test(pos, test_pop_front_single_elem);
    tcase_add_test(pos, test_pop_front_many_elems);

    neg = tcase_create("neg");
    tcase_add_test(neg, test_pop_front_empty);

    suite_add_tcase(s, pos);
    suite_add_tcase(s, neg);

    return s;
}

// ###############################################
//         end pop_front
// ###############################################

// ###############################################
//         start pop_back
// ###############################################

START_TEST(test_pop_back_empty)
{
    ck_assert_ptr_eq(pop_back(NULL), NULL);
}
END_TEST

START_TEST(test_pop_back_single_elem)
{
    int data = 1;
    node_t *tmp = node_create(&data);
    if (tmp == NULL)
        ck_assert_int_eq(1, 0);
    ck_assert_ptr_eq(pop_front(&tmp), &data);
    ck_assert_ptr_eq(tmp, NULL);
}
END_TEST

START_TEST(test_pop_back_many_elems)
{
    int data = 1;
    node_t *tmp1 = node_create(&data);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);
    node_t *tmp2 = node_create(&data);
    if (tmp2 == NULL)
        ck_assert_int_eq(1, 0);
    tmp1->next = tmp2;
    node_t *tmp3 = node_create(&data);
    if (tmp3 == NULL)
        ck_assert_int_eq(1, 0);
    tmp2->next = tmp3;
    ck_assert_ptr_eq(pop_back(&tmp1), &data);
    ck_assert_ptr_eq((*tmp2).next, NULL);
    del_node(tmp1);
    del_node(tmp2);
}
END_TEST

Suite *pop_back_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;

    s = suite_create("pop_back suite");

    pos = tcase_create("pos");
    tcase_add_test(pos, test_pop_back_single_elem);
    tcase_add_test(pos, test_pop_back_many_elems);

    neg = tcase_create("neg");
    tcase_add_test(neg, test_pop_back_empty);

    suite_add_tcase(s, pos);
    suite_add_tcase(s, neg);

    return s;
}

// ###############################################
//         end pop_back
// ###############################################

// ###############################################
//         start insert
// ###############################################

START_TEST(test_insert_empty)
{
    int data = 1;
    node_t *tmp = node_create(&data);
    if (tmp == NULL)
        ck_assert_int_eq(1, 0);
    node_t *head = NULL;
    node_t *before = head;
    insert(&head, tmp, before);
    ck_assert_ptr_eq(head, NULL);
    del_node(tmp);
}
END_TEST

START_TEST(test_insert_nothing)
{
    int data = 1;
    node_t *tmp = node_create(&data);
    if (tmp == NULL)
        ck_assert_int_eq(1, 0);
    node_t *head = tmp;
    node_t *before = head;
    insert(&head, NULL, before);
    ck_assert_ptr_eq(head, tmp);
    del_node(tmp);
}
END_TEST

START_TEST(test_insert_front)
{
    int data = 1;
    node_t *tmp1 = node_create(&data);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);
    node_t *tmp2 = node_create(&data);
    if (tmp2 == NULL)
        ck_assert_int_eq(1, 0);
    tmp1->next = tmp2;
    node_t *tmp3 = node_create(&data);
    if (tmp3 == NULL)
        ck_assert_int_eq(1, 0);
    tmp2->next = tmp3;

    node_t *ins = node_create(&data);
    if (ins == NULL)
        ck_assert_int_eq(1, 0);

    node_t *ptr = tmp1;
    insert(&tmp1, ins, tmp1);
    ck_assert_ptr_eq(tmp1, ins);
    ck_assert_ptr_eq(tmp1->next, ptr);
    list_wipe(tmp1);
}
END_TEST

START_TEST(test_insert_middle)
{
    int data = 1;
    node_t *tmp1 = node_create(&data);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);
    node_t *tmp2 = node_create(&data);
    if (tmp2 == NULL)
        ck_assert_int_eq(1, 0);
    tmp1->next = tmp2;
    node_t *tmp3 = node_create(&data);
    if (tmp3 == NULL)
        ck_assert_int_eq(1, 0);
    tmp2->next = tmp3;

    node_t *ins = node_create(&data);
    if (ins == NULL)
        ck_assert_int_eq(1, 0);

    node_t *ptr = tmp2;
    insert(&tmp1, ins, tmp2);
    ck_assert_ptr_eq(tmp1->next, ins);
    ck_assert_ptr_eq(ins->next, ptr);
    del_node(tmp1);
    del_node(tmp2);
    del_node(tmp3);
    del_node(ins);
}
END_TEST

Suite *insert_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;

    s = suite_create("insert suite");

    pos = tcase_create("pos");
    tcase_add_test(pos, test_insert_front);
    tcase_add_test(pos, test_insert_middle);

    neg = tcase_create("neg");
    tcase_add_test(neg, test_insert_empty);
    tcase_add_test(neg, test_insert_nothing);

    suite_add_tcase(s, pos);
    suite_add_tcase(s, neg);

    return s;
}

// ###############################################
//         end insert
// ###############################################

// ###############################################
//         start copy
// ###############################################

START_TEST(test_copy_empty)
{
    node_t *new_head = NULL;
    ck_assert_int_eq(copy(NULL, &new_head), INCORRECT_PARAMS);
    ck_assert_ptr_eq(new_head, NULL);
}
END_TEST

START_TEST(test_copy_unempty_dst)
{
    int data = 1;
    node_t *tmp1 = node_create(&data);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);

    node_t *new_head = tmp1;
    ck_assert_int_eq(copy(tmp1, &new_head), INCORRECT_PARAMS);
    del_node(tmp1);
}
END_TEST

START_TEST(test_copy_single_elem)
{
    int data = 1;
    node_t *tmp1 = node_create(&data);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);

    node_t *new_head = NULL;
    ck_assert_int_eq(copy(tmp1, &new_head), SUCCESS);
    ck_assert_ptr_eq(new_head->data, &data);
    ck_assert_ptr_eq(new_head->next, NULL);
    del_node(tmp1);
    del_node(new_head);
}
END_TEST

START_TEST(test_copy_many_elems)
{
    int data1 = 1;
    node_t *tmp1 = node_create(&data1);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);

    int data2 = 2;
    node_t *tmp2 = node_create(&data2);
    if (tmp2 == NULL)
        ck_assert_int_eq(1, 0);
    tmp1->next = tmp2;

    node_t *new_head = NULL;
    ck_assert_int_eq(copy(tmp1, &new_head), SUCCESS);
    ck_assert_ptr_eq(new_head->data, &data1);
    ck_assert_ptr_eq(new_head->next->data, &data2);
    ck_assert_int_eq(*(int *)(new_head->data), data1);
    ck_assert_int_eq(*(int *)(new_head->next->data), data2);
    list_wipe(tmp1);
    list_wipe(new_head);
}
END_TEST

Suite *copy_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;

    s = suite_create("copy suite");

    pos = tcase_create("pos");
    tcase_add_test(pos, test_copy_single_elem);
    tcase_add_test(pos, test_copy_many_elems);

    neg = tcase_create("neg");
    tcase_add_test(neg, test_copy_empty);
    tcase_add_test(neg, test_copy_unempty_dst);

    suite_add_tcase(s, pos);
    suite_add_tcase(s, neg);

    return s;
}

// ###############################################
//         end copy
// ###############################################

// ###############################################
//         start append
// ###############################################

START_TEST(test_append_both_empty)
{
    node_t *a_head = NULL;
    node_t *b_head = NULL;

    append(&a_head, &b_head);

    ck_assert_ptr_eq(a_head, NULL);
    ck_assert_ptr_eq(b_head, NULL);
}
END_TEST

START_TEST(test_append_a_empty)
{
    int data = 1;
    node_t *tmp1 = node_create(&data);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);

    node_t *a_head = NULL;

    append(&a_head, &tmp1);

    ck_assert_ptr_eq(a_head->data, &data);
    ck_assert_ptr_eq(tmp1, NULL);

    del_node(a_head);
}
END_TEST

START_TEST(test_append_b_empty)
{
    int data = 1;
    node_t *tmp1 = node_create(&data);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);

    node_t *b_head = NULL;

    append(&tmp1, &b_head);

    ck_assert_ptr_eq(tmp1->data, &data);
    ck_assert_ptr_eq(b_head, NULL);

    del_node(tmp1);
}
END_TEST

Suite *append_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;

    s = suite_create("append suite");

    pos = tcase_create("pos");
    tcase_add_test(pos, test_append_a_empty);
    tcase_add_test(pos, test_append_b_empty);

    neg = tcase_create("neg");
    tcase_add_test(neg, test_append_both_empty);

    suite_add_tcase(s, pos);
    suite_add_tcase(s, neg);

    return s;
}

// ###############################################
//         end append
// ###############################################

// ###############################################
//         start remove_duplicates
// ###############################################

START_TEST(test_remove_duplicates_empty)
{
    node_t *head = NULL;
    remove_duplicates(&head, &int_cmp);

    ck_assert_ptr_eq(head, NULL);
}
END_TEST

START_TEST(test_remove_duplicates_with_duplicates)
{
    int data = 1;
    node_t *tmp1 = node_create(&data);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);
    node_t *tmp2 = node_create(&data);
    if (tmp2 == NULL)
        ck_assert_int_eq(1, 0);
    tmp1->next = tmp2;
    node_t *tmp3 = node_create(&data);
    if (tmp3 == NULL)
        ck_assert_int_eq(1, 0);
    tmp2->next = tmp3;

    remove_duplicates(&tmp1, &int_cmp);

    ck_assert_ptr_eq(tmp1->next, NULL);

    del_node(tmp1);
}
END_TEST

START_TEST(test_remove_duplicates_with_no_duplicates)
{
    int data1 = 1;
    node_t *tmp1 = node_create(&data1);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);
    int data2 = 2;
    node_t *tmp2 = node_create(&data2);
    if (tmp2 == NULL)
        ck_assert_int_eq(1, 0);
    tmp1->next = tmp2;
    int data3 = 3;
    node_t *tmp3 = node_create(&data3);
    if (tmp3 == NULL)
        ck_assert_int_eq(1, 0);
    tmp2->next = tmp3;

    remove_duplicates(&tmp1, &int_cmp);

    ck_assert_ptr_eq(tmp1->next, tmp2);
    ck_assert_ptr_eq(tmp2->next, tmp3);
    ck_assert_ptr_eq(tmp3->next, NULL);
    list_wipe(tmp1);
}
END_TEST

Suite *remove_duplicates_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;

    s = suite_create("remove_duplicates suite");

    pos = tcase_create("pos");
    tcase_add_test(pos, test_remove_duplicates_with_duplicates);
    tcase_add_test(pos, test_remove_duplicates_with_no_duplicates);

    neg = tcase_create("neg");
    tcase_add_test(neg, test_remove_duplicates_empty);

    suite_add_tcase(s, pos);
    suite_add_tcase(s, neg);

    return s;
}

// ###############################################
//         end remove_duplicates
// ###############################################

// ###############################################
//         start sorted_insert
// ###############################################

START_TEST(test_sorted_insert_empty_dst)
{
    int data1 = 1;
    node_t *tmp1 = node_create(&data1);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);
    node_t *head = NULL;
    sorted_insert(&head, tmp1, &int_cmp);
    ck_assert_ptr_eq(head, tmp1);
    ck_assert_ptr_eq(head->data, &data1);
    list_wipe(head);
}
END_TEST

START_TEST(test_sorted_insert_empty_src)
{
    int data1 = 1;
    node_t *tmp1 = node_create(&data1);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);
    node_t *head = tmp1;
    sorted_insert(&head, NULL, &int_cmp);
    ck_assert_ptr_eq(head->next, NULL);
    list_wipe(head);
}
END_TEST

START_TEST(test_sorted_insert_normal)
{
    int data1 = 1;
    node_t *tmp1 = node_create(&data1);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);
    int data2 = 2;
    node_t *tmp2 = node_create(&data2);
    if (tmp2 == NULL)
        ck_assert_int_eq(1, 0);
    tmp1->next = tmp2;
    int data3 = 3;
    node_t *tmp3 = node_create(&data3);
    if (tmp3 == NULL)
        ck_assert_int_eq(1, 0);
    tmp2->next = tmp3;

    int data_ins = 1;
    node_t *ins = node_create(&data_ins);
    if (ins == NULL)
        ck_assert_int_eq(1, 0);

    sorted_insert(&tmp1, ins, &int_cmp);
    ck_assert_ptr_eq(tmp1->next->data, &data_ins);
    ck_assert_ptr_eq(tmp1->next->next->data, &data2);
    list_wipe(tmp1);
}
END_TEST

Suite *sorted_insert_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;

    s = suite_create("sorted_insert suite");

    pos = tcase_create("pos");
    tcase_add_test(pos, test_sorted_insert_empty_dst);
    tcase_add_test(pos, test_sorted_insert_normal);

    neg = tcase_create("neg");
    tcase_add_test(neg, test_sorted_insert_empty_src);

    suite_add_tcase(s, pos);
    suite_add_tcase(s, neg);

    return s;
}

// ###############################################
//         end sorted_insert
// ###############################################

// ###############################################
//         start sort
// ###############################################

START_TEST(test_sort_normal)
{
    int data1 = 3;
    node_t *tmp1 = node_create(&data1);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);
    int data2 = 1;
    node_t *tmp2 = node_create(&data2);
    if (tmp2 == NULL)
        ck_assert_int_eq(1, 0);
    tmp1->next = tmp2;
    int data3 = 2;
    node_t *tmp3 = node_create(&data3);
    if (tmp3 == NULL)
        ck_assert_int_eq(1, 0);
    tmp2->next = tmp3;

    tmp1 = sort(tmp1, &int_cmp);
    ck_assert_ptr_eq(tmp1->data, &data2);
    ck_assert_ptr_eq(tmp1->next->data, &data3);
    ck_assert_ptr_eq(tmp1->next->next->data, &data1);
    list_wipe(tmp1);
}
END_TEST

START_TEST(test_sort_sorted)
{
    int data1 = 1;
    node_t *tmp1 = node_create(&data1);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);
    int data2 = 2;
    node_t *tmp2 = node_create(&data2);
    if (tmp2 == NULL)
        ck_assert_int_eq(1, 0);
    tmp1->next = tmp2;
    int data3 = 3;
    node_t *tmp3 = node_create(&data3);
    if (tmp3 == NULL)
        ck_assert_int_eq(1, 0);
    tmp2->next = tmp3;

    tmp1 = sort(tmp1, &int_cmp);
    ck_assert_ptr_eq(tmp1->data, &data1);
    ck_assert_ptr_eq(tmp1->next->data, &data2);
    ck_assert_ptr_eq(tmp1->next->next->data, &data3);
    list_wipe(tmp1);
}
END_TEST

START_TEST(test_sort_reverse)
{
    int data1 = 3;
    node_t *tmp1 = node_create(&data1);
    if (tmp1 == NULL)
        ck_assert_int_eq(1, 0);
    int data2 = 2;
    node_t *tmp2 = node_create(&data2);
    if (tmp2 == NULL)
        ck_assert_int_eq(1, 0);
    tmp1->next = tmp2;
    int data3 = 1;
    node_t *tmp3 = node_create(&data3);
    if (tmp3 == NULL)
        ck_assert_int_eq(1, 0);
    tmp2->next = tmp3;

    tmp1 = sort(tmp1, &int_cmp);
    ck_assert_ptr_eq(tmp1->data, &data3);
    ck_assert_ptr_eq(tmp1->next->data, &data2);
    ck_assert_ptr_eq(tmp1->next->next->data, &data1);
    list_wipe(tmp1);
}
END_TEST

START_TEST(test_sort_empty)
{
    node_t *head = NULL;
    head = sort(head, &int_cmp);
    ck_assert_ptr_eq(head, NULL);
}
END_TEST

Suite *sort_suite(void)
{
    Suite *s;
    TCase *pos;
    TCase *neg;

    s = suite_create("sort suite");

    pos = tcase_create("pos");
    tcase_add_test(pos, test_sort_normal);
    tcase_add_test(pos, test_sort_sorted);
    tcase_add_test(pos, test_sort_reverse);

    neg = tcase_create("neg");
    tcase_add_test(neg, test_sort_empty);

    suite_add_tcase(s, pos);
    suite_add_tcase(s, neg);

    return s;
}
// ###############################################
//         end sort
// ###############################################

// ###############################################
//         start reverse
// ###############################################

// START_TEST(test_reverse_empty)
// {
//     node_t *head = NULL;
//     reverse(&head);
//     ck_assert_ptr_eq(head, NULL);
// }
// END_TEST

// START_TEST(test_reverse_normal)
// {
//     int data1 = 3;
//     node_t *tmp1 = node_create(&data1);
//     if (tmp1 == NULL)
//         ck_assert_int_eq(1, 0);
//     int data2 = 2;
//     node_t *tmp2 = node_create(&data2);
//     if (tmp2 == NULL)
//         ck_assert_int_eq(1, 0);
//     tmp1->next = tmp2;
//     int data3 = 1;
//     node_t *tmp3 = node_create(&data3);
//     if (tmp3 == NULL)
//         ck_assert_int_eq(1, 0);
//     tmp2->next = tmp3;

//     reverse(&tmp1);
//     ck_assert_ptr_eq(tmp1->data, &data3);
//     ck_assert_ptr_eq(tmp1->next->data, &data2);
//     ck_assert_ptr_eq(tmp1->next->next->data, &data1);
//     list_wipe(tmp1);
// }
// END_TEST

// START_TEST(test_reverse_single_elem)
// {
//     int data1 = 3;
//     node_t *tmp1 = node_create(&data1);
//     if (tmp1 == NULL)
//         ck_assert_int_eq(1, 0);

//     reverse(&tmp1);
//     ck_assert_ptr_eq(tmp1->data, &data1);
//     ck_assert_ptr_eq(tmp1->next, NULL);
//     list_wipe(tmp1);
// }
// END_TEST

// Suite *reverse_suite(void)
// {
//     Suite *s;
//     TCase *pos;
//     TCase *neg;

//     s = suite_create("reverse suite");

//     pos = tcase_create("pos");
//     tcase_add_test(pos, test_reverse_single_elem);
//     tcase_add_test(pos, test_reverse_normal);

//     neg = tcase_create("neg");
//     tcase_add_test(neg, test_reverse_empty);

//     suite_add_tcase(s, pos);
//     suite_add_tcase(s, neg);

//     return s;
// }

// ###############################################
//         end reverse
// ###############################################