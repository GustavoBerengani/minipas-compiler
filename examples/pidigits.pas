program PiDigits;

var
  digits, scale, piValue, divisor, current, count: integer;

function ArcTanInverse(inverse, precision: integer): integer;
var
  term, sum, denominator, part, sign: integer;
begin
  term := precision / inverse;
  sum := term;
  denominator := 3;
  sign := -1;

  while term <> 0 do
  begin
    term := term / (inverse * inverse);
    part := term / denominator;
    if sign < 0 then
      sum := sum - part
    else
      sum := sum + part;
    denominator := denominator + 2;
    sign := -sign
  end;
  return sum
end;

begin
  { Formula de Machin com 15 casas de ponto fixo. }
  digits := param(1);
  if digits > 13 then
    digits := 13;

  if digits > 0 then
  begin
    scale := 1000000000000000;
    piValue := 16 * ArcTanInverse(5, scale) -
               4 * ArcTanInverse(239, scale);
    divisor := scale;
    count := 0;

    while count < digits do
    begin
      current := (piValue / divisor) mod 10;
      write(current);
      count := count + 1;
      if (count = 1) and (digits > 1) then
        write('.');
      divisor := divisor / 10
    end
  end;
  writeln()
end.
