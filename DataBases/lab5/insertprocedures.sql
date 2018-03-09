use lab1tema
go


go
create procedure usp_insertPublishers
@name varchar(50),
@address varchar(100)
as
begin
	declare @error_no int
    select @error_no=dbo.validatePublishers(@name, @address) 
	if @error_no = 1
	begin
		insert into Publishers (publisher_name,publisher_address)
		values(@name, @address)
	end
		else
	begin
		raiserror('Publisher already in table',16,1)
	end
end

go



go 
create procedure usp_insertBook
@book_id int,
@book_name varchar(50),
@isbn varchar(50),
@back_id int
as
begin
	declare @error_no int
	select @error_no = dbo.validateBook(@book_id)

	if @error_no <>0
		raiserror('Error in insert books',16,10)
	insert into Books(book_id,book_name,isbn,back_id)
	values(@book_id,@book_name,@isbn,@back_id)
end

go



go

create procedure usp_insertPublisherBook
@book_id int,
@publisher_id int
as
begin
	declare @error_no int
	set @error_no = dbo.validatePublisherBook(@book_id,@publisher_id)
	if @error_no = 0
	begin
		insert into PublisherBook(book_id,publisher_id)
		values(@book_id,@publisher_id)
	end
	else
		raiserror('Already in table',16,1)
end

go

go
create procedure usp_insertClients
@client_id int,
@client_name varchar(50),
@email varchar(50),
@client_address varchar(100)
as
begin
	declare @error_no int
	set @error_no = dbo.validateClients(@client_id,@client_name,@email)
	if @error_no <> 0
		raiserror('Error in Clients insert',16,1)
	insert into Clients(client_name,email,client_address)
	values(@client_name,@email,@client_address)

end

go


go
create procedure usp_insertOrders
@order_id int,
@order_no int,
@order_desc varchar(50),
@client_id int
as
begin
	declare @error_no int
	--set @error_no = dbo.validateOrders(@order_id,@client_id)
	--if @error_no = 1
		--raiserror('Error in Orders insert', 16,1)
	insert into Orders(order_no,order_description,client_id)
	values(@order_no,@order_desc,@client_id)
end

go




