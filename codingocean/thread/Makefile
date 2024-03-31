CPP := g++
CPPFLAGS := -std=c++14 -Wall -Wextra -Werror -pedantic -O3
#CPPFLAGS := -std=c++14 -Wall -Wextra -Werror -pedantic -O3 -fext-numeric-literals
# :=は即時展開、=は遅延展開であり、
# :=は再代入不可、=は再代入可という違いがある

TARGET := mutex
SRCS := mutex.cpp
OBJS := $(SRCS:.cpp=.o) # 

.PHONY: all clean

# 各ターゲットは依存関係とレシピで構成される

# allはターゲット名であり、依存関係がないため、常にレシピが実行される
all: $(TARGET)

# $@はターゲット名に置換される
# $^は依存ファイル名に置換される。
$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

# %.cppから%.oを作成するためのパターンルール
# $<は最初の依存ファイル名に置換される
%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $@ $<

# cleanターゲットは生成されたファイルを削除するレシピ
# $(RM)は通常rm -fに設定されている
clean:
	$(RM) $(TARGET) $(OBJS)
