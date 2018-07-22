#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Label/Label.h"
#include "../Textbox/TextBox.h"
#include <cassert>

struct LabelMOCK:Label {  LabelMOCK(int width) :Label(width) { } };

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest{		
	TEST_CLASS(UnitTest1){
	public:
	
		LabelMOCK* label= new LabelMOCK(20);
		
		TEST_METHOD(getVisibilty)	{
			Graphics *graphics = new Graphics(STD_INPUT_HANDLE);
			graphics->setCursorVisibility(true);
			Assert::AreEqual(graphics->getCursorVisbility(),true);
			graphics->setCursorVisibility(false);
			Assert::AreEqual(graphics->getCursorVisbility(), false);
		}

		TEST_METHOD(getWidth){
			label->set_width(10);
			Assert::AreEqual(label->getWidth(),10);
		}

		TEST_METHOD(getHeight){
			label->set_height(10);
			Assert::AreEqual(label->getHeight(),10);
		}

		TEST_METHOD(getValue){
			string var = "testVar";
			label->setValue(var);
			Assert::AreEqual(label->getValue().compare(var),0);
		}
	};
}