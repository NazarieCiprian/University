use lab1tema
go

create function validatePublishers
(@name varchar(50),
@address varchar(100))
returns int
as
begin
	declare @nr int
	declare @error_no int
	set @nr = 0
	select @nr = count(*) from Publishers p where @name = p.publisher_name and @address = p.publisher_address
	if @nr = 0 
		set @error_no = 1
	else
		set @error_no = 0
	return @error_no
end 

go

create function validateBook
(@book_id int)
returns int
as
begin
	declare @error_no int
	declare @nr int
	select @nr = count(*) from Books b where @book_id = b.book_id
	if @nr = 0
		set @error_no = 0
	else
		set @error_no = 1
	
	return @error_no
end

go

create function validatePublisherBook
(@book_id int, @publisher_id int)
returns int 
as
begin
	declare  @error_no int
	declare @nr1 int
	declare @nr2 int
	declare @nr3 int
	select @nr1=count(*) from PublisherBook pb where pb.book_id = @book_id and pb.publisher_id=@publisher_id
	select @nr2=count(*) from Books b where b.book_id = @book_id
	select @nr3=count(*) from Publishers pb where pb.publisher_id = @publisher_id
	if @nr1 <>0 or @nr2 = 0 or @nr3 =0
		set @error_no = 1
	else
		set @error_no = 0

	return @error_no
end

go

create function validateClients
(@client_id int,@client_name varchar(50),@email varchar(100))
returns int
as
begin
	declare @error_no int
	declare @nr1 int
	declare @nr2 int
	select @nr1=count(*) from Clients c where @client_name = c.client_name and c.email = @email
	select @nr2= count(*) from Clients c where @client_id = c.client_id
	if @nr1 <> 0 or @nr2 <> 0
		set @error_no = 1
	else
		set @error_no = 0
	return @error_no
end

/*
go
create function validateOrders
(@order_id int,@client_id int)
returns int
as
begin
	declare @nr1 int
	declare @nr2 int
	declare @error_no int
	select @nr1 = count(*) from Clients c where c.client_id = @client_id
	select @nr2 = count(*) from Orders o where o.order_id =  @order_id
	if  @nr2 <> 0
		set @error_no = 1
	else
		set @error_no = 0
	return @error_no
end
*/