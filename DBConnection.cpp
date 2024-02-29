#include <iostream>
#include <sql.h>
#include <sqlext.h>

// Student class
class Student {
public:
    std::string name;
    int age;

    Student(const std::string& name, int age) : name(name), age(age) {}
};

// Database connection class
class DBConnection {
private:
    SQLHENV henv;
    SQLHDBC hdbc;
    SQLHSTMT hstmt;

public:
    DBConnection() {
        // Initialize the environment handle
        SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
        SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

        // Allocate the connection handle
        SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);

        // Connect to the SQL server
        SQLDriverConnect(hdbc, NULL, (SQLCHAR*)"DRIVER={SQL Server};SERVER=localhost;DATABASE=YourDatabase;UID=YourUsername;PWD=YourPassword;", SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);

        // Allocate the statement handle
        SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    }

    ~DBConnection() {
        // Free the statement handle
        SQLFreeHandle(SQL_HANDLE_STMT, hstmt);

        // Disconnect and free the connection handle
        SQLDisconnect(hdbc);
        SQLFreeHandle(SQL_HANDLE_DBC, hdbc);

        // Free the environment handle
        SQLFreeHandle(SQL_HANDLE_ENV, henv);
    }

    void findAllStudents() {
        // Execute the SQL query to fetch all student records
        SQLExecDirect(hstmt, (SQLCHAR*)"SELECT * FROM Students", SQL_NTS);

        // Fetch and print the results
        SQLCHAR name[256];
        SQLINTEGER age;
        while (SQLFetch(hstmt) == SQL_SUCCESS) {
            SQLGetData(hstmt, 1, SQL_C_CHAR, name, sizeof(name), NULL);
            SQLGetData(hstmt, 2, SQL_C_LONG, &age, 0, NULL);
            std::cout << "Name: " << name << ", Age: " << age << std::endl;
        }
    }

    void saveStudent(const Student& student) {
        // Prepare the SQL statement to insert a student record
        std::string sql = "INSERT INTO Students (Name, Age) VALUES ('" + student.name + "', " + std::to_string(student.age) + ")";
        SQLExecDirect(hstmt, (SQLCHAR*)sql.c_str(), SQL_NTS);
    }
};

int main() {
    // Create a database connection
    DBConnection dbConnection;

    // Create a Student object
    Student student("John Doe", 20);

    // Call the findAllStudents method
    dbConnection.findAllStudents();

    // Call the saveStudent method
    dbConnection.saveStudent(student);

    return 0;
}
