use lab1tema
go

create procedure insert_table_Authors
@norows int
as
begin
	declare @n int
	declare @name varchar(50)
	set @n=1
	--set identity_insert Authors on
	while @n<=@norows
	begin
		set @name = 'john' + CONVERT(varchar(5),@n)
		insert into Authors
		values(@n,@name,30,32)
		set @n = @n +1
	end
end

go

execute insert_table_Authors 10
select * from Authors


