#include "pch.h"
#include "KeyEvent.h"
#include <sstream>

String keyCodeToString(const sf::Keyboard::Key keyCode)
{
	switch (keyCode)
	{
		case sf::Keyboard::A:
			return STRINGIFY(A);
		case sf::Keyboard::B:
			return STRINGIFY(B);
		case sf::Keyboard::C:
			return STRINGIFY(C);
		case sf::Keyboard::D:
			return STRINGIFY(D);
		case sf::Keyboard::E:
			return STRINGIFY(E);
		case sf::Keyboard::F:
			return STRINGIFY(F);
		case sf::Keyboard::G:
			return STRINGIFY(G);
		case sf::Keyboard::H:
			return STRINGIFY(H);
		case sf::Keyboard::I:
			return STRINGIFY(I);
		case sf::Keyboard::J:
			return STRINGIFY(J);
		case sf::Keyboard::K:
			return STRINGIFY(K);
		case sf::Keyboard::L:
			return STRINGIFY(L);
		case sf::Keyboard::M:
			return STRINGIFY(M);
		case sf::Keyboard::N:
			return STRINGIFY(N);
		case sf::Keyboard::O:
			return STRINGIFY(O);
		case sf::Keyboard::P:
			return STRINGIFY(P);
		case sf::Keyboard::Q:
			return STRINGIFY(Q);
		case sf::Keyboard::R:
			return STRINGIFY(R);
		case sf::Keyboard::S:
			return STRINGIFY(S);
		case sf::Keyboard::T:
			return STRINGIFY(T);
		case sf::Keyboard::U:
			return STRINGIFY(U);
		case sf::Keyboard::V:
			return STRINGIFY(V);
		case sf::Keyboard::W:
			return STRINGIFY(W);
		case sf::Keyboard::X:
			return STRINGIFY(X);
		case sf::Keyboard::Y:
			return STRINGIFY(Y);
		case sf::Keyboard::Z:
			return STRINGIFY(Z);
		case sf::Keyboard::Num0:
			return STRINGIFY(Num0);
		case sf::Keyboard::Num1:
			return STRINGIFY(Num1);
		case sf::Keyboard::Num2:
			return STRINGIFY(Num2);
		case sf::Keyboard::Num3:
			return STRINGIFY(Num3);
		case sf::Keyboard::Num4:
			return STRINGIFY(Num4);
		case sf::Keyboard::Num5:
			return STRINGIFY(Num5);
		case sf::Keyboard::Num6:
			return STRINGIFY(Num6);
		case sf::Keyboard::Num7:
			return STRINGIFY(Num7);
		case sf::Keyboard::Num8:
			return STRINGIFY(Num8);
		case sf::Keyboard::Num9:
			return STRINGIFY(Num9);
		case sf::Keyboard::Escape:
			return STRINGIFY(Escape);
		case sf::Keyboard::LControl:
			return STRINGIFY(LControl);
		case sf::Keyboard::LShift:
			return STRINGIFY(LShift);
		case sf::Keyboard::LAlt:
			return STRINGIFY(LAlt);
		case sf::Keyboard::LSystem:
			return STRINGIFY(LSystem);
		case sf::Keyboard::RControl:
			return STRINGIFY(RControl);
		case sf::Keyboard::RShift:
			return STRINGIFY(RShift);
		case sf::Keyboard::RAlt:
			return STRINGIFY(RAlt);
		case sf::Keyboard::RSystem:
			return STRINGIFY(RSystem);
		case sf::Keyboard::Menu:
			return STRINGIFY(Menu);
		case sf::Keyboard::LBracket:
			return STRINGIFY(LBracket);
		case sf::Keyboard::RBracket:
			return STRINGIFY(RBracket);
		case sf::Keyboard::Semicolon:
			return STRINGIFY(Semicolon);
		case sf::Keyboard::Comma:
			return STRINGIFY(Comma);
		case sf::Keyboard::Period:
			return STRINGIFY(Period);
		case sf::Keyboard::Quote:
			return STRINGIFY(Quote);
		case sf::Keyboard::Slash:
			return STRINGIFY(Slash);
		case sf::Keyboard::Backslash:
			return STRINGIFY(Backslash);
		case sf::Keyboard::Tilde:
			return STRINGIFY(Tilde);
		case sf::Keyboard::Equal:
			return STRINGIFY(Equal);
		case sf::Keyboard::Hyphen:
			return STRINGIFY(Hyphen);
		case sf::Keyboard::Space:
			return STRINGIFY(Space);
		case sf::Keyboard::Enter:
			return STRINGIFY(Enter);
		case sf::Keyboard::Backspace:
			return STRINGIFY(Backspace);
		case sf::Keyboard::Tab:
			return STRINGIFY(Tab);
		case sf::Keyboard::PageUp:
			return STRINGIFY(PageUp);
		case sf::Keyboard::PageDown:
			return STRINGIFY(PageDown);
		case sf::Keyboard::End:
			return STRINGIFY(End);
		case sf::Keyboard::Home:
			return STRINGIFY(Home);
		case sf::Keyboard::Insert:
			return STRINGIFY(Insert);
		case sf::Keyboard::Delete:
			return STRINGIFY(Delete);
		case sf::Keyboard::Add:
			return STRINGIFY(Add);
		case sf::Keyboard::Subtract:
			return STRINGIFY(Subtract);
		case sf::Keyboard::Multiply:
			return STRINGIFY(Multiply);
		case sf::Keyboard::Divide:
			return STRINGIFY(Divide);
		case sf::Keyboard::Left:
			return STRINGIFY(Left);
		case sf::Keyboard::Right:
			return STRINGIFY(Right);
		case sf::Keyboard::Up:
			return STRINGIFY(Up);
		case sf::Keyboard::Down:
			return STRINGIFY(Down);
		case sf::Keyboard::Numpad0:
			return STRINGIFY(Numpad0);
		case sf::Keyboard::Numpad1:
			return STRINGIFY(Numpad1);
		case sf::Keyboard::Numpad2:
			return STRINGIFY(Numpad2);
		case sf::Keyboard::Numpad3:
			return STRINGIFY(Numpad3);
		case sf::Keyboard::Numpad4:
			return STRINGIFY(Numpad4);
		case sf::Keyboard::Numpad5:
			return STRINGIFY(Numpad5);
		case sf::Keyboard::Numpad6:
			return STRINGIFY(Numpad6);
		case sf::Keyboard::Numpad7:
			return STRINGIFY(Numpad7);
		case sf::Keyboard::Numpad8:
			return STRINGIFY(Numpad8);
		case sf::Keyboard::Numpad9:
			return STRINGIFY(Numpad9);
		case sf::Keyboard::F1:
			return STRINGIFY(F1);
		case sf::Keyboard::F2:
			return STRINGIFY(F2);
		case sf::Keyboard::F3:
			return STRINGIFY(F3);
		case sf::Keyboard::F4:
			return STRINGIFY(F4);
		case sf::Keyboard::F5:
			return STRINGIFY(F5);
		case sf::Keyboard::F6:
			return STRINGIFY(F6);
		case sf::Keyboard::F7:
			return STRINGIFY(F7);
		case sf::Keyboard::F8:
			return STRINGIFY(F8);
		case sf::Keyboard::F9:
			return STRINGIFY(F9);
		case sf::Keyboard::F10:
			return STRINGIFY(F10);
		case sf::Keyboard::F11:
			return STRINGIFY(F12);
		case sf::Keyboard::F12:
			return STRINGIFY(F12);
		case sf::Keyboard::F13:
			return STRINGIFY(F13);
		case sf::Keyboard::F14:
			return STRINGIFY(F4);
		case sf::Keyboard::F15:
			return STRINGIFY(F15);
		case sf::Keyboard::Pause:
			return STRINGIFY(Pause);
		default:
			return STRINGIFY(Unknown);
	}
}

sf::Keyboard::Key KeyEvent::GetKeyCode() const
{
	return m_KeyCode;
}

KeyEvent::KeyEvent(const sf::Keyboard::Key keycode):
	m_KeyCode(keycode)
{
}

KeyPressedEvent::KeyPressedEvent(const sf::Keyboard::Key keycode):
	KeyEvent(keycode)
{
}

std::string KeyPressedEvent::ToString() const
{
	std::stringstream ss;
	ss << "KeyPressedEvent: " << keyCodeToString(m_KeyCode);
	return ss.str();
}

KeyReleasedEvent::KeyReleasedEvent(const sf::Keyboard::Key keycode):
	KeyEvent(keycode)
{
}

std::string KeyReleasedEvent::ToString() const
{
	std::stringstream ss;
	ss << "KeyReleasedEvent: " << keyCodeToString(m_KeyCode);
	return ss.str();
}
