#include <gtest/gtest.h>

extern "C" 
{
    #include "add_composition.h"
    #include "view_composition.h"
    #include "string_io.h"
}

TEST(Test, read_string) {
    FILE* fp = NULL;

    char input1[] = "[\n\t{\n\t\t\"author\": \"lol omg\"";
    fp = fmemopen(input1, 27, "r");
    EXPECT_EQ(strcmp(read_string_from_file(fp), "lol omg"), 0);
    fclose(fp);

    char input2[] = ",\n\t\t\"author\": \"aloh\"";
    fp = fmemopen(input2, 21, "r");
    EXPECT_EQ(strcmp(read_string_from_file(fp), "aloh"), 0);
    fclose(fp);

    char input3[] = "\n\t\"performer\": \"Mamota\"";
    fp = fmemopen(input3, 24, "r");
    EXPECT_EQ(strcmp(read_string_from_file(fp), "Mamota"), 0);
    fclose(fp);

    char input4[] = "\"duration\": \"123\"";
    fp = fmemopen(input4, 18, "r");
    EXPECT_EQ(strcmp(read_string_from_file(fp), "123"), 0);
    fclose(fp);

    char input5[] = ",\n\t{\n\t\t\"author\" \"Taylor Swift\"";
    fp = fmemopen(input5, 31, "r");
    EXPECT_EQ(strcmp(read_string_from_file(fp), "Taylor Swift"), 0);
    fclose(fp);
}