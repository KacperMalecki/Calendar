#include "Button.h"

void ChangeState(Button *button, ButtonState newState) {
    if (newState != button->state) {
        button->state = newState;
        switch (newState) {
            case BUTTON_NORMAL:         button->currentClr = button->normal;        break;
            case BUTTON_HIGHLIGHTED:    button->currentClr = button->highlighted;   break;
            case BUTTON_PRESSED:        button->currentClr = button->pressed;       break;
        }
    }
}

void InitButton(Button *button, Rectangle rect, Color normal, Color highlighted, Color pressed) {
    //  setting internal state of the button
    button->state = BUTTON_NORMAL;
    button->currentClr = normal;
    ChangeState(button, BUTTON_NORMAL);
    //  setting values
    button->rect = rect;
    button->normal = normal;
    button->highlighted = highlighted;
    button->pressed = pressed;
}

void UpdateButton(Button *button, Vector2 mousePosition) {
    bool isMouseClicked = IsMouseButtonPressed(0);
    bool isMouseReleased = IsMouseButtonReleased(0);
    bool isMouseHeldDown = IsMouseButtonDown(0);
    //  cursor inside the button
    if (CheckCollisionPointRec(mousePosition, button->rect)) {
        //  mouse button released
        if (button->state == BUTTON_PRESSED && isMouseReleased && button->onRelease != nullptr) {
            //  use function pointer
            if (button->state == BUTTON_PRESSED && button->onRelease != nullptr) {
                button->onRelease();
            }
            ChangeState(button, BUTTON_NORMAL);
        }
        //  mouse button clicked
        else if (isMouseClicked) {
            if (button->state != BUTTON_PRESSED) {
                ChangeState(button, BUTTON_PRESSED);
            }
        }
        //  mouse button held down
        else if (isMouseHeldDown) {
            if (button->state == BUTTON_NORMAL) {
                ChangeState(button, BUTTON_HIGHLIGHTED);
            }
        }
        //  no mouse input
        else {
            ChangeState(button, BUTTON_HIGHLIGHTED);
        }
    }
    //  cursor outside the button
    else {
        //  if not (held down and the state is "Pressed") - change to normal
        if (!isMouseHeldDown || button->state != BUTTON_PRESSED) {
            ChangeState(button, BUTTON_NORMAL);
        }
    }
}