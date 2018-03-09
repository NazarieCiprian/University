use lab1tema 
go


create function validateRemoveBook
(@id1 int)
returns int
as
begin
	declare @error_no int
	declare @nr1 int
	declare @nr2 int
	select @nr1 = count(*) from Books b where b.book_id = @id1
	select @nr2 = count(*) from PublisherBook pb where pb.book_id = @id1
	if @nr1 = 0 or @nr2 <> 0
		set @error_no =1
	else
		set @error_no =0
	return @error_no
end

go

create function validateRemovePublisher
(@publisher_id int)
returns int
as
begin
	declare @error_no int
	declare @nr int
	declare @nr2 int
	select @nr = count(*) from Publishers p where p.publisher_id = @publisher_id
	select @nr2 = count(*) from PublisherBook pb where pb.publisher_id = @publisher_id
	if @nr = 0 or @nr2 <> 0
		set @error_no = 1
	else
		set @error_no = 0
	return @error_no
end

go

create function validateRemovePublisherBook
(@publisher_id int, @book_id int)
returns int
as
begin
	declare @error_no int
	declare @nr int
	
	select @nr = count(*) from PublisherBook p where p.book_id =@book_id and p.publisher_id =@publisher_id

	if @nr = 0
		set @error_no =1
	else
		set @error_no = 0
	return @error_no
end

go

create function validateRemoveClients
(@client_id int)
returns int
as
begin
	declare @error_no int
	declare @nr int
	declare @nr1 int
	select @nr = count(*) from Clients c where c.client_id = @client_id
	select @nr1 = count(*) from Orders o where o.client_id = @client_id
	if @nr = 0 or @nr1 <> 0
		set @error_no =1
	else
		set @error_no = 0
	return @error_no
end

go

create function validateRemoveOrders
(@order_id int)
returns int
as
begin
	declare @error_no int
	declare @nr int
	
	select @nr = count(*) from Orders o where o.order_id = @order_id

	if @nr = 0
		set @error_no =1
	else
		set @error_no = 0
	return @error_no
end