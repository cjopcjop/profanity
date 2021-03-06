#include <stdlib.h>
#include <string.h>
#include <head-unit.h>
#include "common.h"

void replace_one_substr(void)
{
    char *string = "it is a string";
    char *sub = "is";
    char *new = "was";

    char *result = str_replace(string, sub, new);

    assert_string_equals("it was a string", result);
}

void replace_one_substr_beginning(void)
{
    char *string = "it is a string";
    char *sub = "it";
    char *new = "that";

    char *result = str_replace(string, sub, new);

    assert_string_equals("that is a string", result);
}

void replace_one_substr_end(void)
{
    char *string = "it is a string";
    char *sub = "string";
    char *new = "thing";

    char *result = str_replace(string, sub, new);

    assert_string_equals("it is a thing", result);
}

void replace_two_substr(void)
{
    char *string = "it is a is string";
    char *sub = "is";
    char *new = "was";

    char *result = str_replace(string, sub, new);

    assert_string_equals("it was a was string", result);
}

void replace_char(void)
{
    char *string = "some & a thing & something else";
    char *sub = "&";
    char *new = "&amp;";

    char *result = str_replace(string, sub, new);

    assert_string_equals("some &amp; a thing &amp; something else", result);
}

void replace_when_none(void)
{
    char *string = "its another string";
    char *sub = "haha";
    char *new = "replaced";

    char *result = str_replace(string, sub, new);

    assert_string_equals("its another string", result);
}

void replace_when_match(void)
{
    char *string = "hello";
    char *sub = "hello";
    char *new = "goodbye";

    char *result = str_replace(string, sub, new);

    assert_string_equals("goodbye", result);
}

void replace_when_string_empty(void)
{
    char *string = "";
    char *sub = "hello";
    char *new = "goodbye";

    char *result = str_replace(string, sub, new);

    assert_string_equals("", result);
}

void replace_when_string_null(void)
{
    char *string = NULL;
    char *sub = "hello";
    char *new = "goodbye";

    char *result = str_replace(string, sub, new);

    assert_is_null(result);
}

void replace_when_sub_empty(void)
{
    char *string = "hello";
    char *sub = "";
    char *new = "goodbye";

    char *result = str_replace(string, sub, new);

    assert_string_equals("hello", result);
}

void replace_when_sub_null(void)
{
    char *string = "hello";
    char *sub = NULL;
    char *new = "goodbye";

    char *result = str_replace(string, sub, new);

    assert_string_equals("hello", result);
}

void replace_when_new_empty(void)
{
    char *string = "hello";
    char *sub = "hello";
    char *new = "";

    char *result = str_replace(string, sub, new);

    assert_string_equals("", result);
}

void replace_when_new_null(void)
{
    char *string = "hello";
    char *sub = "hello";
    char *new = NULL;

    char *result = str_replace(string, sub, new);

    assert_string_equals("hello", result);
}

void register_common_tests(void)
{
    TEST_MODULE("common tests");
    TEST(replace_one_substr);
    TEST(replace_one_substr_beginning);
    TEST(replace_one_substr_end);
    TEST(replace_two_substr);
    TEST(replace_char);
    TEST(replace_when_none);
    TEST(replace_when_match);
    TEST(replace_when_string_empty);
    TEST(replace_when_string_null);
    TEST(replace_when_sub_empty);
    TEST(replace_when_sub_null);
    TEST(replace_when_new_empty);
    TEST(replace_when_new_null);
}
