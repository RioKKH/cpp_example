#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
ThisとThatの２つのElementクラスがあり、それぞれにacceptメソッドがある。
Visitorクラスは、訪問する要素の型に基づいて適切なvisitメソッドを呼び出す。
UpVisitorとDownVisitorは、それぞれ異なる操作をThisとThatに対して行う。

Pythonの例ではgetattr関数とメソッド名の動的な生成を利用して、C++のオーバー
ロードを模倣している。
これによいｒ、新しいElementクラスを追加するときに、対応するvisitメソッドを
Visitorクラスに追加するだけで済む。
"""

class Element:
    def accept(self, visitor):
        visitor.visit(self)

class This(Element):
    def thiss(self):
        return "This"

class That(Element):
    def that(self):
        return "That"

class Visitor:
    def visit(self, element):
        method_name = 'visit_' + type(element).__name__
        method = getattr(self, method_name, self.visit_default)
        method(element)

    def visit_default(self, element):
        raise NotImplementedError("No visit_{} method".format(type(element).__name__))


class UpVisitor(Visitor):
    def visit_This(self, element):
        print("do Up on " + element.thiss())

    def visit_That(self, element):
        print("do Up on " + element.that())

class DownVisitor(Visitor):
    def visit_This(self, element):
        print("do Down on " + element.thiss())

    def visit_That(self, element):
        print("do Down on " + element.that())

aThis = This()
aThat = That()

up = UpVisitor()
down = DownVisitor()

aThis.accept(up)
aThat.accept(up)

aThis.accept(down)
aThat.accept(down)
