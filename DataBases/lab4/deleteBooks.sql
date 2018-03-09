use lab1tema
go

create procedure delete_table_Books
@nrofrows int
as
begin

	declare @n int
	set @n =1
	while @n<=@nrofrows
	begin
		delete from Books
		where @n = book_id
		set @n = @n +1
	end
end

go
execute delete_table_Books 10
