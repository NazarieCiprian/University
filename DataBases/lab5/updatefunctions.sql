use lab1tema
go
--validate publisher update
create function validateUpdatePublisher
(@publisher_id int)
returns int
as
begin
	declare @error_no int
	declare @nr int
	select @nr = count(*) from Publishers p where p.publisher_id = @publisher_id

	if @nr = 0
		set @error_no = 1
	else
		set @error_no = 0
	return @error_no
end
go
--validate book update
create function validateUpdateBooks
(@book_id int)
returns int
as
begin
	declare @error_no int
	declare @nr int
	select @nr = count(*) from Books b where b.book_id = @book_id

	if @nr = 0
		set @error_no = 1
	else
		set @error_no = 0
	return @error_no
end

go

--validate publisherbook

create function validateUpdatePublisherBooks
(@book_id int,@publisher_id int)
returns int
as
begin
	declare @error_no int
	declare @nr1 int
	declare @nr2 int
	declare @nr3 int
	select @nr1 = count(*) from Books b where b.book_id = @book_id
	select @nr2 = count (*) from Publishers p where p.publisher_id = @publisher_id
	select @nr3 = count(*) from PublisherBook pb where pb.publisher_id = @publisher_id or pb.book_id = @book_id
	if @nr1 = 0 or @nr2 = 0 or @nr2 = 0
		set @error_no = 1
	else
		set @error_no = 0
	return @error_no

end

go

--validate clients

create function validateUpdateClients
(@client_id int)
returns int
as
begin
	declare @error_no int
	declare @nr int
	select @nr = count(*) from Clients c where c.client_id = @client_id

	if @nr = 0
		set @error_no = 1
	else
		set @error_no =0
	return @error_no
end

go

--validate orders

create function validateUpdateOrders
(@order_id int,@client_id int)
returns int
as
begin
	declare @error_no int
	declare @nr1 int
	declare @nr2 int
	select @nr1 = count(*) from Orders o where o.order_id =@order_id
	select @nr2 = count(*) from Clients c where c.client_id = @client_id

	if @nr1 = 0 or @nr2 = 0
		set @error_no =1
	else
		set @error_no =0
	return @error_no
end