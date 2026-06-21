; ModuleID = 'fibonacci'
source_filename = "fibonacci.pas"

@__minipas_argc = internal global i32 0
@__minipas_argv = internal global ptr null
@position = internal global i64 0
@0 = private unnamed_addr constant [5 x i8] c"%lld\00", align 1
@1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

declare i32 @printf(ptr, ...)

declare i32 @atoi(ptr)

define i64 @fib(i64 %value) {
entry:
  %index = alloca i64, align 8
  %temporary = alloca i64, align 8
  %current = alloca i64, align 8
  %previous = alloca i64, align 8
  %value1 = alloca i64, align 8
  store i64 %value, ptr %value1, align 4
  store i64 0, ptr %previous, align 4
  store i64 0, ptr %current, align 4
  store i64 0, ptr %temporary, align 4
  store i64 0, ptr %index, align 4
  %value.value = load i64, ptr %value1, align 4
  %lesseq.value = icmp sle i64 %value.value, 0
  br i1 %lesseq.value, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  ret i64 0

if.end:                                           ; No predecessors!
  ret i64 0

if.else:                                          ; preds = %entry
  store i64 0, ptr %previous, align 4
  store i64 1, ptr %current, align 4
  store i64 2, ptr %index, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.body, %if.else
  %for.value = load i64, ptr %index, align 4
  %value.value2 = load i64, ptr %value1, align 4
  %0 = icmp sle i64 %for.value, %value.value2
  br i1 %0, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %previous.value = load i64, ptr %previous, align 4
  %current.value = load i64, ptr %current, align 4
  %add.value = add i64 %previous.value, %current.value
  store i64 %add.value, ptr %temporary, align 4
  %current.value3 = load i64, ptr %current, align 4
  store i64 %current.value3, ptr %previous, align 4
  %temporary.value = load i64, ptr %temporary, align 4
  store i64 %temporary.value, ptr %current, align 4
  %1 = load i64, ptr %index, align 4
  %2 = add i64 %1, 1
  store i64 %2, ptr %index, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  %current.value4 = load i64, ptr %current, align 4
  ret i64 %current.value4
}

define i32 @main(i32 %argc, ptr %argv) {
entry:
  store i32 %argc, ptr @__minipas_argc, align 4
  store ptr %argv, ptr @__minipas_argv, align 8
  %argv.value = load ptr, ptr @__minipas_argv, align 8
  %argv.slot = getelementptr inbounds ptr, ptr %argv.value, i64 1
  %argv.text = load ptr, ptr %argv.slot, align 8
  %arg.number = call i32 @atoi(ptr %argv.text)
  %arg.integer = sext i32 %arg.number to i64
  store i64 %arg.integer, ptr @position, align 4
  %position.value = load i64, ptr @position, align 4
  %fib.result = call i64 @fib(i64 %position.value)
  %0 = call i32 (ptr, ...) @printf(ptr @0, i64 %fib.result)
  %1 = call i32 (ptr, ...) @printf(ptr @1)
  ret i32 0
}
