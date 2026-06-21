program PiDigits;

var
  digits, q, r, t, k, digit, limit, count, newR, newDigit: integer;

begin
  (* Algoritmo spigot de Jeremy Gibbons, usando apenas inteiros. *)
  digits := param(1);
  q := 1;
  r := 0;
  t := 1;
  k := 1;
  digit := 3;
  limit := 3;
  count := 0;

  while count < digits do
  begin
    if (4 * q + r - t) < (digit * t) then
    begin
      write(digit);
      count := count + 1;
      if (count = 1) and (digits > 1) then
        write('.');
      newR := 10 * (r - digit * t);
      digit := ((10 * (3 * q + r)) / t) - (10 * digit);
      q := 10 * q;
      r := newR
    end
    else
    begin
      newR := (2 * q + r) * limit;
      newDigit := (q * (7 * k) + 2 + r * limit) / (t * limit);
      q := q * k;
      t := t * limit;
      limit := limit + 2;
      k := k + 1;
      digit := newDigit;
      r := newR
    end
  end;
  writeln()
end.
