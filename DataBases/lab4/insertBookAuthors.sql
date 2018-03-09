use lab1tema
go

create procedure insert_table_BookAuthor
@nrofrows int
as
begin
	declare @n int
	declare @name varchar(50)
	declare @fk int
	set @n=1
	while @n<=@nrofrows
	begin
		select top 1 @fk=a.author_id  from Authors a where a.author_name like 'john%'
		insert into BookAuthor
		values(@n,@fk)
		set @n = @n+1
	end

end

go
execute insert_table_BookAuthor 10

select * from BookAuthor
