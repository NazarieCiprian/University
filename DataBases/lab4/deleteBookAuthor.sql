use lab1tema
go

create procedure delete_table_BookAuthor
@nrofrows int
as
begin
	declare @n int
	set @n =1
	while @n<=@nrofrows
	begin
		delete from BookAuthor
		where book_id=@n
		set @n = @n+1
	end
end

go
execute delete_table_BookAuthor 10