use lab1tema
go

create procedure insert_table_Books
@norows int
as
begin
	declare @n int
	declare @name varchar(50)
	declare @fk int
	set @n =1
	while @n<=@norows
	begin
		set @name = 'book'+convert(varchar(5),@n)
		select top 1 @fk =b.back_id from Backs b where b.back_quality='quality' 
		insert into Books
		values(@n,@name,@n,@fk)
		set @n = @n +1
	end
end

go
execute insert_table_Books 10

