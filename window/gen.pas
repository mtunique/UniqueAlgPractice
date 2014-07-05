const
   ouf='window';
   ou='.in';
   inf=10000000;
var
   n,k:longint;
   fout:string;
   ch:char;
procedure make(maxn:longint;c:shortstring);
var
   i,j,x:longint;
begin
   fout:=ouf+c+ou;
   randomize;
   assign(output,fout);rewrite(output);
   n:=random(maxn);k:=random(n);
   writeln(n,' ',k);
   for i:=1 to n-1 do
   write(random(inf)-5000000,' ');
   writeln(random(inf)-5000000);
   close(output);
end;

begin
   for ch:='1' to '2' do make(500,ch);
   for ch:='3' to '5' do make(100000,ch);
   for ch:='6' to '9' do make(1000000,ch);
   make(1000000,'10');
end.
