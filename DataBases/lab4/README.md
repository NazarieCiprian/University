# Databases lab4 assignment
After you finished the design of your database, the development team is interested
in obtaining some results regarding the performance of your design. In order to
record the different test configurations and their results you create the following
relational structure:
 Tests – holds information regarding the different test configurations
 Tables – holds information regarding the tables that might take part in a test
 TestTables – a link table between Tests and Tables. It holds information regarding
the participation of each table to each test
 Views – a set f views that are present in the database and are used to asses the
performance of certain select queries
 TestViews – a link table between Tests and Views. It holds information regarding
the participation of each view to each test
 TestRuns – a table containing information about different test runs. A test run
involves the following:
 1) deleting the information from the tables;
 2) inserting rows in the tables;
 3) evaluating the views
 TestRunTables – contains the performance information for every tables in which
values were inserted
 TestRunViews – contains the performance information for every view in the test
Your task is to implement a set of stored procedures for evaluating and storing the
results of the tests. The test must be available for at least three tables:
 - a table with one column as the primary key and no foreign key,
 - a table with one column as the primary key and at least one foreign key,
 - a table with two columns as the primary key,
an three views:
 - a view with a select statement working on a single table,
 - a view with a select statement working on at least two tables,
 - a view with a select statement working on at least two tables and having a
group by clause.

