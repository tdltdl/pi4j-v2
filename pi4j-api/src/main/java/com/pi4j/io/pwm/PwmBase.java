package com.pi4j.io.pwm;

/*-
 * #%L
 * **********************************************************************
 * ORGANIZATION  :  Pi4J
 * PROJECT       :  Pi4J :: LIBRARY  :: Java Library (API)
 * FILENAME      :  PwmBase.java
 *
 * This file is part of the Pi4J project. More information about
 * this project can be found here:  https://pi4j.com/
 * **********************************************************************
 * %%
 * Copyright (C) 2012 - 2019 Pi4J
 * %%
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * #L%
 */

import com.pi4j.io.IOBase;

import java.io.IOException;

public abstract class PwmBase extends IOBase<Pwm, PwmConfig, PwmProvider> implements Pwm {

    protected int range = -1;
    protected int frequency = -1;
    protected int dutyCycle = -1;
    protected boolean onState = false;

    public PwmBase(PwmProvider provider, PwmConfig config) {
        super(provider, config);
        this.name = "PWM-" + config.address();
        // TODO :: INITIALIZE PWM SETTINGS WITH DEFAULTS
    }

    @Override
    public int getDutyCycle() throws IOException {
        return this.dutyCycle;
    }

    @Override
    public int getFrequency() throws IOException {
        return this.frequency;
    }

    @Override
    public void setDutyCycle(int dutyCycle) throws IOException {
        this.dutyCycle = dutyCycle;
    }

    @Override
    public void setFrequency(int frequency) throws IOException {
        this.frequency = frequency;
    }

    @Override
    public int getRange() throws IOException {
        return this.range;
    }

    @Override
    public void setRange(int range) throws IOException {
        this.range = range;
    }

    @Override
    public boolean isOn() {
        return this.onState;
    }
}
