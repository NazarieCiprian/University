use lab1tema
go


create procedure usp_removePublisher
@id int
as

begin
	declare @error_no int
	
	select @error_no = dbo.validateRemovePublisher(@id)
	
	if @error_no = 1
		raiserror('Error in removePubliser',16,10)
	delete from Publishers
	where publisher_id = @id
end

go

create procedure usp_removeBooks
@id int
as
begin
	declare @error_no int
	
	select @error_no = dbo.validateRemoveBook(@id)
	
	if @error_no = 1
		raiserror('Error in removeBook',16,10)

	delete from Books
	where book_id = @id
end

go

create procedure usp_removePublisherBook
@book_id int,
@publisher_id int
as
begin
	declare @error_no int
	
	select @error_no = dbo.validateRemovePublisherBook(@book_id,@publisher_id)
	
	if @error_no = 1
		raiserror('Error in removePubliser',16,10)

	delete from PublisherBook
	where book_id = @book_id and publisher_id = @publisher_id
end

go

create procedure usp_removeClients
@client_id int
as
begin
	declare @error_no int
	
	select @error_no = dbo.validateRemoveClients(@client_id)
	
	if @error_no = 1
		raiserror('Error in removePubliser',16,10)

	delete from Clients
	where client_id = @client_id
end

go

create procedure usp_removeOrders
@id int
as
begin
	declare @error_no int
	
	select @error_no = dbo.validateRemoveOrders(@id)
	
	if @error_no = 1
		raiserror('Error in removePubliser',16,10)

	delete from Orders
	where order_id = @id
end

