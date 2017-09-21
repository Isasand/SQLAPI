#include <stdio.h>  
#include <SQLAPI.h> 

int main(int argc, char* argv[])
{
	SAConnection con; // create connection object

	try
	{
		// connect to database
		con.Connect(
			"",     // database name
			"",   // user name
			"",   // password
			SA_MySQL_Client);

		printf("We are connected!\n");

		// Disconnect is optional
		// autodisconnect will ocur in destructor if needed
		con.Disconnect();

		printf("We are disconnected!\n");
	}
	catch (SAException &x)
	{
		// SAConnection::Rollback()
		// can also throw an exception
		// (if a network error for example),
		// we will be ready
		try
		{
			// on error rollback changes
			con.Rollback();
		}
		catch (SAException &)
		{
		}
		// print error message
		printf("%s\n", (const char*)x.ErrText());
	}

	return 0;
}