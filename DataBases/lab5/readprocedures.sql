use lab1tema
go

create procedure usp_readPublishers
as
begin
	select * from Publishers

end

go

create procedure usp_readBooks
as
begin
	select * from Books
end

go

create procedure usp_readPublisherBook
as
begin
	select * from PublisherBook
end

go

create procedure usp_readClients
as
begin
	select * from Clients
end

go

create procedure usp_readOrders
as
begin
	select * from Orders
end

go
