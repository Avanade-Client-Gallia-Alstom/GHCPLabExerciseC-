#include <gtest/gtest.h>
#include "DBConnection.cpp"

// Test fixture for DBConnection class
class DBConnectionTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up the database connection before each test case
        dbConnection = new DBConnection();
    }

    void TearDown() override {
        // Clean up the database connection after each test case
        delete dbConnection;
    }

    DBConnection* dbConnection;
};

// Test case for saveStudent method
TEST_F(DBConnectionTest, SaveStudentTest) {
    // Create a student object
    Student student("John Doe", 20);

    // Save the student record
    dbConnection->saveStudent(student);

    // TODO: Add assertions to verify the saved student record
    // For example, you can fetch the student record from the database and compare it with the expected values
    // ASSERT_... macros can be used to perform assertions
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
