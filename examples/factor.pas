program Factor;

var
  number, divisor: integer;
  first: boolean;

procedure ShowFactor(value: integer);
begin
  if first then
  begin
    write(value);
    first := false
  end
  else
    write(' ', value)
end;

begin
  { O primeiro parametro e o numero que sera fatorado. }
  number := param(1);
  divisor := 2;
  first := true;

  while number > 1 do
  begin
    while (number mod divisor) = 0 do
    begin
      ShowFactor(divisor);
      number := number / divisor
    end;
    divisor := divisor + 1
  end;
  writeln()
end.
