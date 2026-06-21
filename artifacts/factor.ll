; ModuleID = 'factor'
source_filename = "factor.pas"

@__minipas_argc = internal global i32 0
@__minipas_argv = internal global ptr null
@number = internal global i64 0
@divisor = internal global i64 0
@first = internal global i1 false
@0 = private unnamed_addr constant [5 x i8] c"%lld\00", align 1
@1 = private unnamed_addr constant [2 x i8] c" \00", align 1
@2 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@3 = private unnamed_addr constant [5 x i8] c"%lld\00", align 1
@4 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

declare i32 @printf(ptr, ...)

declare i32 @atoi(ptr)

define void @showfactor(i64 %value) {
entry:
  %value1 = alloca i64, align 8
  store i64 %value, ptr %value1, align 4
  %first.value = load i1, ptr @first, align 1
  br i1 %first.value, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %value.value = load i64, ptr %value1, align 4
  %0 = call i32 (ptr, ...) @printf(ptr @0, i64 %value.value)
  store i1 false, ptr @first, align 1
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  ret void

if.else:                                          ; preds = %entry
  %1 = call i32 (ptr, ...) @printf(ptr @2, ptr @1)
  %value.value2 = load i64, ptr %value1, align 4
  %2 = call i32 (ptr, ...) @printf(ptr @3, i64 %value.value2)
  br label %if.end
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
  store i64 %arg.integer, ptr @number, align 4
  store i64 2, ptr @divisor, align 4
  store i1 true, ptr @first, align 1
  br label %while.cond

while.cond:                                       ; preds = %while.end3, %entry
  %number.value = load i64, ptr @number, align 4
  %greater.value = icmp sgt i64 %number.value, 1
  br i1 %greater.value, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  br label %while.cond1

while.end:                                        ; preds = %while.cond
  %0 = call i32 (ptr, ...) @printf(ptr @4)
  ret i32 0

while.cond1:                                      ; preds = %while.body2, %while.body
  %number.value4 = load i64, ptr @number, align 4
  %divisor.value = load i64, ptr @divisor, align 4
  %mod.value = srem i64 %number.value4, %divisor.value
  %equal.value = icmp eq i64 %mod.value, 0
  br i1 %equal.value, label %while.body2, label %while.end3

while.body2:                                      ; preds = %while.cond1
  %divisor.value5 = load i64, ptr @divisor, align 4
  call void @showfactor(i64 %divisor.value5)
  %number.value6 = load i64, ptr @number, align 4
  %divisor.value7 = load i64, ptr @divisor, align 4
  %div.value = sdiv i64 %number.value6, %divisor.value7
  store i64 %div.value, ptr @number, align 4
  br label %while.cond1

while.end3:                                       ; preds = %while.cond1
  %divisor.value8 = load i64, ptr @divisor, align 4
  %add.value = add i64 %divisor.value8, 1
  store i64 %add.value, ptr @divisor, align 4
  br label %while.cond
}
