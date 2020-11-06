# gordian_knot
Code for an Escape Room game
----
   Escape room game where the player has to untie a knot of wires.
   The wires are connected to a voltage divider ladder and labeled Red, Green, Blue and Yellow.
   The analog pins are connected to a contact which has an RGB LED next to it.
   When the game starts the target order is shuffled and indicated with the LEDs next to the contacts.
   The object is to move the wires by color to the contacts indicated by the LEDS.

   Future plans:
   There will be timeouts involved.
   No more than two contacts can be broken at any time or the game reshuffles.
   No contacts can be broken for more then x-seconds, or the game reshuffles.
