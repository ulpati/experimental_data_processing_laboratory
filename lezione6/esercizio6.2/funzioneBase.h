#pragma once

class FunzioneBase {

	public:
		// costruttore
		virtual double Eval(double x) const = 0;

		// distruttore
		virtual ~FunzioneBase() {}

};