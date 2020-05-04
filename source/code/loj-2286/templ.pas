type
    u32 = dword;
    u64 = qword;
    u32_p = ^u32;
    u64_p = ^u64;
    longint_p = ^longint;

function next_integer(x : u32) : u32; inline;
begin
    x := x xor (x << 13);
    x := x xor (x >> 17);
    x := x xor (x << 5);
    exit(x);
end;

function output_arr(a_in : pointer; size : u32) : boolean;
var
    blocks : u32;
    a, a_ed : u32_p;
    ret, x : u32;
begin
    if size mod 4 <> 0 then begin
        writeln(-1);
        exit(false);
    end;

    blocks := size div 4;
    ret := size;
    a := a_in;
    a_ed := a + blocks;
    x := 23333333;

    while a < a_ed do begin
        ret := ret xor (a[0] + x);
        x := x xor (x << 13);
        x := x xor (x >> 17);
        x := x xor (x << 5);
        inc(a);
    end;

    writeln(ret);
    exit(true);
end;

// ====== header ======

procedure init_data(a : u32_p; n : longint; seed : u32);
var
    a_ed : u32_p;
begin
    a_ed := a + n;
    while a < a_ed do begin
        seed := next_integer(seed);
        a[0] := seed;
        inc(a);
    end;
end;

procedure Sorting_main();
var
    n : longint;
    seed : u32;
    a : u32_p;
    i : u32;
begin
    read(n, seed);

    a := Getmem(n * sizeof(u32));
    init_data(a, n, seed);

    // sort(a, n);

    output_arr(a, n * sizeof(u32));
end;

procedure Game_main();
var
    n, q : longint;
    s1, s2 : ansistring;
    anss : u32_p;
    q_x, q_y, q_len : longint_p;
    i : longint;
begin
    readln(n, q);
    readln(s1);
    readln(s2);

    anss := Getmem(q * sizeof(u32));
    q_x := Getmem(q * sizeof(longint));
    q_y := Getmem(q * sizeof(longint));
    q_len := Getmem(q * sizeof(longint));

    for i := 0 to q - 1 do begin
        read(q_x[i], q_y[i], q_len[i]);
    end;

    // solve(n, q, s1, s2, q_x, q_y, q_len, anss);

    output_arr(anss, q * sizeof(u32));
end;

procedure Parentheses_main();
var
    n : longint;
    s : ansistring;
    ans : u32;
begin
    read(n);
    read(s);

    // ans := solve(n, s);

    writeln(ans);
end;

var
    task_id : longint;

begin
    read(task_id);

    if task_id = 1 then begin
        Sorting_main();
    end else if task_id = 2 then begin
        Game_main();
    end else if task_id = 3 then begin
        Parentheses_main();
    end;
    close(input); close(output);
end.
