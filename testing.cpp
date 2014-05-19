#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

class LogicError : public std::logic_error {
public:

    LogicError( ) : std::logic_error( "" ) {

    }

    virtual const char *what( ) const throw () {
        return m_message.c_str( );
    }

    virtual ~LogicError( ) throw () {

    }

protected:
    std::string m_message;
};

class EmptyArgument : public LogicError {
public:

    EmptyArgument( ) {
        m_message = "Error: empty argument";
    }
};

class BadArgument : public LogicError {
public:

    BadArgument( const std::string &argument ) {
        m_message = "Bad argument: " + argument;
    }
};

bool isCorrectMove( const std::string &textOfMove )
throw( EmptyArgument, BadArgument );

TEST( test001, exceptionTest ) {
    std::string textOfMove;

    ASSERT_THROW({
                     isCorrectMove( textOfMove );
                 }, EmptyArgument);
}

TEST( test002, exceptionTest ) {
    std::string textOfMove = "";

    ASSERT_THROW({
                     isCorrectMove( textOfMove );
                 }, EmptyArgument);
}

TEST( test003, exceptionTest ) {
    std::string textOfMove = " ";

    ASSERT_THROW({
                     isCorrectMove( textOfMove );
                 }, BadArgument);
}

TEST( test004, exceptionTest ) {
    std::string textOfMove = "BSN";

    ASSERT_THROW({
                     isCorrectMove( textOfMove );
                 }, BadArgument);
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
