use lab1tema
go



alter procedure usp_updatePublishers
@publisher_id int,
@publisher_name varchar(50),
@publisher_address varchar(50)
as
begin
	declare @error_no int
	select @error_no=dbo.validateUpdatePublisher(@publisher_id)
	if @error_no = 1
		raiserror('Error in updatePublisher',16,10)
	update Publishers
	set publisher_name = @publisher_name, publisher_address = @publisher_address
	where publisher_id = @publisher_id 
end
go


create procedure usp_updateBooks
@book_id int,
@book_name varchar(50),
@isbn varchar(50),
@back_id int
as
begin
	declare @error_no int
	select @error_no = dbo.validateUpdateBooks(@book_id)

	if @error_no = 1
		raiserror('Error in updateBooks',16,10)
	update Books
	set book_name=@book_name, isbn = @isbn, back_id = @back_id
	where book_id = @book_id 
end
go
create procedure usp_updatePublisherBook
@book_id int,
@publisher_id int
as
begin
	
	declare @error_no int

	select @error_no = dbo. validateUpdatePublisherBooks(@book_id,@publisher_id)

	if @error_no = 1
		raiserror('Error in publisherBook',16,10)
	update PublisherBook
	set book_id = @book_id, publisher_id = @publisher_id
	where book_id = @book_id or publisher_id = @publisher_id
end

go

alter procedure usp_updateClients
@client_id int,
@client_name varchar(50),
@email varchar(50),
@client_address varchar(50)
as
begin

	declare @error_no int
	
	select @error_no = dbo.validateUpdateClients(@client_id)

	if @error_no =1
		raiserror('Error in updateClients',16,10)

	update Clients
	set client_name = @client_name, email = @email, client_address = @client_address
	where @client_id = client_id 
end

go

alter procedure usp_updateOrders
@order_id int,
@oder_no int,
@order_desc varchar(50),
@client_id int
as
begin
	
	declare @error_no int

	select @error_no = dbo.validateUpdateOrders(@order_id,@client_id)

	if @error_no = 1
		raiserror('Error in updateOrders',16,10)
	update Orders
	set order_no = @oder_no, order_description = @order_desc, client_id = @client_id
	where @order_id = order_id 
end
go

select * from Publishers


