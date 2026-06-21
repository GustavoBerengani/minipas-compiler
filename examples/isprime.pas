program IsPrime;

var
  number: integer;

function Prime(value: integer): boolean;
var
  divisor: integer;
  result: boolean;
begin
  if value < 2 then
    result := false
  else
  begin
    divisor := 2;
    result := true;
    while (divisor * divisor <= value) and result do
    begin
      if (value mod divisor) = 0 then
        result := false;
      divisor := divisor + 1
    end
  end;
  return result
end;

begin
  number := param(1);
  writeln(Prime(number))
end.
