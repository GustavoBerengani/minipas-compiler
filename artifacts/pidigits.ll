; ModuleID = 'pidigits'
source_filename = "pidigits.pas"

@__minipas_argc = internal global i32 0
@__minipas_argv = internal global ptr null
@digits = internal global i64 0
@scale = internal global i64 0
@pivalue = internal global i64 0
@divisor = internal global i64 0
@current = internal global i64 0
@count = internal global i64 0
@0 = private unnamed_addr constant [5 x i8] c"%lld\00", align 1
@1 = private unnamed_addr constant [2 x i8] c".\00", align 1
@2 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@3 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

declare i32 @printf(ptr, ...)

declare i32 @atoi(ptr)

define i64 @arctaninverse(i64 %inverse, i64 %precision) {
entry:
  %sign = alloca i64, align 8
  %part = alloca i64, align 8
  %denominator = alloca i64, align 8
  %sum = alloca i64, align 8
  %term = alloca i64, align 8
  %precision2 = alloca i64, align 8
  %inverse1 = alloca i64, align 8
  store i64 %inverse, ptr %inverse1, align 4
  store i64 %precision, ptr %precision2, align 4
  store i64 0, ptr %term, align 4
  store i64 0, ptr %sum, align 4
  store i64 0, ptr %denominator, align 4
  store i64 0, ptr %part, align 4
  store i64 0, ptr %sign, align 4
  %precision.value = load i64, ptr %precision2, align 4
  %inverse.value = load i64, ptr %inverse1, align 4
  %div.value = sdiv i64 %precision.value, %inverse.value
  store i64 %div.value, ptr %term, align 4
  %term.value = load i64, ptr %term, align 4
  store i64 %term.value, ptr %sum, align 4
  store i64 3, ptr %denominator, align 4
  store i64 -1, ptr %sign, align 4
  br label %while.cond

while.cond:                                       ; preds = %if.end, %entry
  %term.value3 = load i64, ptr %term, align 4
  %different.value = icmp ne i64 %term.value3, 0
  br i1 %different.value, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %term.value4 = load i64, ptr %term, align 4
  %inverse.value5 = load i64, ptr %inverse1, align 4
  %inverse.value6 = load i64, ptr %inverse1, align 4
  %mul.value = mul i64 %inverse.value5, %inverse.value6
  %div.value7 = sdiv i64 %term.value4, %mul.value
  store i64 %div.value7, ptr %term, align 4
  %term.value8 = load i64, ptr %term, align 4
  %denominator.value = load i64, ptr %denominator, align 4
  %div.value9 = sdiv i64 %term.value8, %denominator.value
  store i64 %div.value9, ptr %part, align 4
  %sign.value = load i64, ptr %sign, align 4
  %less.value = icmp slt i64 %sign.value, 0
  br i1 %less.value, label %if.then, label %if.else

while.end:                                        ; preds = %while.cond
  %sum.value15 = load i64, ptr %sum, align 4
  ret i64 %sum.value15

if.then:                                          ; preds = %while.body
  %sum.value = load i64, ptr %sum, align 4
  %part.value = load i64, ptr %part, align 4
  %sub.value = sub i64 %sum.value, %part.value
  store i64 %sub.value, ptr %sum, align 4
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  %denominator.value12 = load i64, ptr %denominator, align 4
  %add.value13 = add i64 %denominator.value12, 2
  store i64 %add.value13, ptr %denominator, align 4
  %sign.value14 = load i64, ptr %sign, align 4
  %negative.value = sub i64 0, %sign.value14
  store i64 %negative.value, ptr %sign, align 4
  br label %while.cond

if.else:                                          ; preds = %while.body
  %sum.value10 = load i64, ptr %sum, align 4
  %part.value11 = load i64, ptr %part, align 4
  %add.value = add i64 %sum.value10, %part.value11
  store i64 %add.value, ptr %sum, align 4
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
  store i64 %arg.integer, ptr @digits, align 4
  %digits.value = load i64, ptr @digits, align 4
  %greater.value = icmp sgt i64 %digits.value, 13
  br i1 %greater.value, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i64 13, ptr @digits, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %digits.value1 = load i64, ptr @digits, align 4
  %greater.value2 = icmp sgt i64 %digits.value1, 0
  br i1 %greater.value2, label %if.then3, label %if.end4

if.then3:                                         ; preds = %if.end
  store i64 1000000000000000, ptr @scale, align 4
  %scale.value = load i64, ptr @scale, align 4
  %arctaninverse.result = call i64 @arctaninverse(i64 5, i64 %scale.value)
  %mul.value = mul i64 16, %arctaninverse.result
  %scale.value5 = load i64, ptr @scale, align 4
  %arctaninverse.result6 = call i64 @arctaninverse(i64 239, i64 %scale.value5)
  %mul.value7 = mul i64 4, %arctaninverse.result6
  %sub.value = sub i64 %mul.value, %mul.value7
  store i64 %sub.value, ptr @pivalue, align 4
  %scale.value8 = load i64, ptr @scale, align 4
  store i64 %scale.value8, ptr @divisor, align 4
  store i64 0, ptr @count, align 4
  br label %while.cond

if.end4:                                          ; preds = %while.end, %if.end
  %0 = call i32 (ptr, ...) @printf(ptr @3)
  ret i32 0

while.cond:                                       ; preds = %if.end15, %if.then3
  %count.value = load i64, ptr @count, align 4
  %digits.value9 = load i64, ptr @digits, align 4
  %less.value = icmp slt i64 %count.value, %digits.value9
  br i1 %less.value, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %pivalue.value = load i64, ptr @pivalue, align 4
  %divisor.value = load i64, ptr @divisor, align 4
  %div.value = sdiv i64 %pivalue.value, %divisor.value
  %mod.value = srem i64 %div.value, 10
  store i64 %mod.value, ptr @current, align 4
  %current.value = load i64, ptr @current, align 4
  %1 = call i32 (ptr, ...) @printf(ptr @0, i64 %current.value)
  %count.value10 = load i64, ptr @count, align 4
  %add.value = add i64 %count.value10, 1
  store i64 %add.value, ptr @count, align 4
  %count.value11 = load i64, ptr @count, align 4
  %equal.value = icmp eq i64 %count.value11, 1
  %digits.value12 = load i64, ptr @digits, align 4
  %greater.value13 = icmp sgt i64 %digits.value12, 1
  %and.value = and i1 %equal.value, %greater.value13
  br i1 %and.value, label %if.then14, label %if.end15

while.end:                                        ; preds = %while.cond
  br label %if.end4

if.then14:                                        ; preds = %while.body
  %2 = call i32 (ptr, ...) @printf(ptr @2, ptr @1)
  br label %if.end15

if.end15:                                         ; preds = %if.then14, %while.body
  %divisor.value16 = load i64, ptr @divisor, align 4
  %div.value17 = sdiv i64 %divisor.value16, 10
  store i64 %div.value17, ptr @divisor, align 4
  br label %while.cond
}
