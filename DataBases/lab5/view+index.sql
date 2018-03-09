use lab1tema
go
create view NrofBooksAtPublisher
as
select count(b.book_id) as nrofbooks,b.book_name
from Books b
inner join PublisherBook pb on pb.book_id = b.book_id
inner join Publishers p on p.publisher_id = pb.publisher_id
where p.publisher_name = 'Nemira'
group by b.book_name

go
execute usp_readBooks
execute usp_readPublishers
execute usp_readPublisherBook
select *
from NrofBooksAtPublisher
create nonclustered index idx_Books_bookname
on Books(book_name)

create nonclustered index idx_Publishers_publishername
on	Publishers(publisher_name)

create nonclustered index idx_PublisherBook_bookid
on PublisherBook(book_id)

create nonclustered index idx_PublisherBook_publisherid
on PublisherBook(publisher_id)

select *
from PublisherBook

select p.publisher_name
from Publishers p
select *
from Books
select b.book_name
from Books b
order by b.book_name
go
create view NrOfClientsWithDescription
as
select c.client_name, count(c.client_id) as NrOfClients
from Clients c
inner join Orders o on o.client_id = c.client_id
where o.order_description like '%book%'
group by c.client_name

go
select *
from NrOfClientsWithDescription
execute usp_readClients
execute usp_readOrders
create nonclustered index idx_Clients_client_name
on Clients(client_name)

create nonclustered index idx_Orders_orderDescription
on Orders(order_description)

select *
from Orders

go
select * from Books
select * from Publishers
select * from PublisherBook