use lab1tema
go

--#=============================================================
-- insert into books

declare @book_id int
declare @book_name varchar(50)
declare @isbn varchar(50)
declare @back_id int


set @book_id = 11
set @book_name = 'Red and black'
set @isbn = '122454352434'
set @back_id = 1
--execute usp_insertBook @book_id,@book_name, @isbn, @back_id

--#===========================================================
--insertbooks
	
begin try
	execute usp_insertBook @book_id,@book_name, @isbn, @back_id
end try
begin catch
	select 
	error_number () as error_no,
	error_message () as error_msg;
end catch	

execute usp_readBooks
--#===================================================================
--insert publishers

declare @publisher_name varchar(50)
declare @publisher_address varchar(50)
set @publisher_address = 'some adress123'
set @publisher_name = 'some name12'
begin try
	execute usp_insertPublishers @publisher_name,@publisher_address
end try
begin catch
	select
	error_number() as error_no,
	error_message() as error_msg;
end catch

execute usp_readPublishers
--#========================================
-- insert publishersbooks

declare @book_id1 int
declare @publisher_id1 int

set @book_id1=3
set @publisher_id1 = 1

begin try
	execute usp_insertPublisherBook @book_id1,@publisher_id1
end try
begin catch
	select
	error_number() as error_no,
	error_message() as error_msg;
end catch

execute usp_readPublisherBook
--#======================================
-- insert clients

declare @client_id int
declare @client_name varchar(50)
declare @email varchar(50)
declare @client_address varchar(100)

set @client_id = 101
set @client_name = 'john1'
set @email = 'something@otherthing1'
set @client_address = 'some address'


begin try
	execute usp_insertClients @client_id,@client_name,@email,@client_address
end try
begin catch
	select
	error_number() as error_no,
	error_message() as error_msg;
end catch

execute usp_readClients
--#===============================================================
--insert orders

declare @order_id int
declare @order_no int
declare @order_desc varchar(50)
declare @client_id1 int

set @order_id = 122
set @order_no = 2456443
set @order_desc = 'some description'
set @client_id1 = 1


begin try
	execute usp_insertOrders @order_id, @order_no, @order_desc, @client_id1
end try
begin catch
	select
	error_number() as error_no,
	error_message() as error_msg;
end catch

execute usp_readOrders

execute usp_removePublisher 1003
execute usp_removePublisherBook 1, 1
execute usp_removeClients 1002
execute usp_removeOrders 2004
select * from Books
select * from Backs
select * from Publishers
select * from PublisherBook
select * from Clients
select * from Orders


go

--#=====================================
-- remove from books
declare @book_id int
set @book_id=11

begin try
	execute usp_removeBooks @book_id
end try
begin catch
	select 
	error_number () as error_no,
	error_message () as error_msg;
end catch	

execute usp_readBooks
execute usp_readPublisherBook
--#==============================================
--remove from publisher

declare @publisher_id int
set @publisher_id = 1008


begin try
	execute usp_removePublisher @publisher_id
end try
begin catch
	select 
	error_number () as error_no,
	error_message () as error_msg;
end catch	

execute usp_readPublishers
execute usp_readPublisherBook
select * from Publishers

--#===================================================
-- remove from publisherbook

declare @publisher_id1 int
declare @book_id1 int

set @publisher_id1 =1
set @book_id1 =1

begin try
	execute usp_removePublisherBook @book_id1 , @publisher_id1
end try
begin catch
	select 
	error_number () as error_no,
	error_message () as error_msg;
end catch

execute usp_readPublisherBook
--#=====================================================================
-- remove orders

declare @order_id int
set @order_id  =  3
begin try
	execute usp_removeOrders @order_id
end try
begin catch
	select 
	error_number () as error_no,
	error_message () as error_msg;
end catch

execute usp_readOrders
execute usp_readClients
--#======================================================================
-- remove Clients

declare @client_id int
set @client_id = 1

begin try
	execute usp_removeClients @client_id
end try
begin catch
	select 
	error_number () as error_no,
	error_message () as error_msg;
end catch


execute usp_readClients
execute usp_readOrders
--#===============================================================================

go
--#====================================
-- update books
declare @book_id int
declare @book_name varchar(50)
declare @isbn varchar(50)
declare @back_id int

set @book_id =11
set @book_name = 'some other name3'
set @isbn = '25432134510'
set @back_id = 3
begin try
	execute usp_updateBooks @book_id,@book_name,@isbn,@back_id
end try
begin catch
	select 
	error_number () as error_no,
	error_message () as error_msg;
end catch

execute usp_readBooks
--#===========================================================
--update publisher
declare @publisher_id int
declare @publisher_name varchar(50)
declare @publisher_address varchar(50)

set @publisher_id = 1008
set @publisher_address = 'some adres134s'
set @publisher_name = 'some name4323'

begin try
	execute usp_updatePublishers @publisher_id, @publisher_name,@publisher_address
end try
begin catch
	select 
	error_number () as error_no,
	error_message () as error_msg;
end catch

execute usp_readPublishers
--#========================================================================
--update publiserbook

declare @publisher_id1 int
declare @book_id1 int

set @publisher_id1 =1004
set @book_id1 = 2

begin try
	execute usp_updatePublisherBook @book_id1, @publisher_id1
end try
begin catch
	select 
	error_number () as error_no,
	error_message () as error_msg;
end catch

execute usp_readPublisherBook
execute usp_readPublishers
--#===================================================================
-- update clients

declare @client_id int
declare @client_name varchar(50)
declare @email varchar(50)
declare @client_address varchar(100)

set @client_id = 1003
set @client_name = 'john1'
set @email = 'something@otherthing13'
set @client_address = 'some address13'
begin try
	execute usp_updateClients @client_id, @client_name, @email, @client_address
end try
begin catch
	select 
	error_number () as error_no,
	error_message () as error_msg;
end catch

execute usp_readClients
--#========================================================
-- update orders

declare @order_id int
declare @order_no int
declare @order_desc varchar(50)
declare @client_id1 int

set @order_id = 1003
set @order_no = 2456443
set @order_desc = 'some description'
set @client_id1 = 1
begin try
	execute usp_updateOrders @order_id, @order_no, @order_desc, @client_id1
end try
begin catch
	select 
	error_number () as error_no,
	error_message () as error_msg;
end catch

execute usp_readOrders

select * from Books
select * from Publishers

