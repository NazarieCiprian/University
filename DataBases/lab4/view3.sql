use lab1tema
go

create view view3
as
select b.book_name,a.author_name
from Authors a,Books b
group by b.book_name,
		 a.author_name

select * from view3