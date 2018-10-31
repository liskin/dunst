#include "../src/menu.c"

#include "greatest.h"

#include <glib.h>

TEST test_extract_urls_from_empty_string(void)
{
        char *urls = extract_urls("");
        ASSERT_EQ_FMT(NULL, (void*)urls, "%p");
        g_free(urls);
        PASS();
}

TEST test_extract_urls_from_no_urls_string(void)
{
        char *urls = extract_urls("You got a new message from your friend");
        ASSERT_EQ_FMT(NULL, (void*)urls, "%p");
        g_free(urls);
        PASS();
}

TEST test_extract_urls_from_one_url_string(void)
{
        char *urls = extract_urls("Hi from https://www.example.com!");
        ASSERT_STR_EQ("https://www.example.com", urls);
        g_free(urls);
        PASS();
}

TEST test_extract_urls_from_two_url_string(void)
{
        char *urls = extract_urls("Hi from https://www.example.com and ftp://www.example.com!");
        ASSERT_STR_EQ("https://www.example.com\nftp://www.example.com", urls);
        g_free(urls);
        PASS();
}


SUITE(suite_menu)
{
        RUN_TEST(test_extract_urls_from_empty_string);
        RUN_TEST(test_extract_urls_from_no_urls_string);
        RUN_TEST(test_extract_urls_from_one_url_string);
        RUN_TEST(test_extract_urls_from_two_url_string);
}
/* vim: set tabstop=8 shiftwidth=8 expandtab textwidth=0: */
