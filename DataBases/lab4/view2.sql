 use lab1tema
go

create view twoTables
as
select *
from Books b, Authors a
where b.isbn> 5 and a.author_name like 'j%'

select *
from twoTables