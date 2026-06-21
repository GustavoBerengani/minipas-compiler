program Fibonacci;

var
  position: integer;

function Fib(value: integer): integer;
var
  previous, current, temporary, index: integer;
begin
  if value <= 0 then
    return 0
  else
  begin
    previous := 0;
    current := 1;
    for index := 2 to value do
    begin
      temporary := previous + current;
      previous := current;
      current := temporary
    end;
    return current
  end
end;

begin
  position := param(1);
  writeln(Fib(position))
end.
