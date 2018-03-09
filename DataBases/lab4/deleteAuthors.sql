use lab1tema
go


create procedure delete_table_Authors
@norows int
as
begin
	declare @n int
	set @n = 1
	while @n<=@norows
	begin
		delete from Authors
		where author_id = @n
		set @n = @n +1
	end
end

go
execute delete_table_Authors 10

select * from Authors