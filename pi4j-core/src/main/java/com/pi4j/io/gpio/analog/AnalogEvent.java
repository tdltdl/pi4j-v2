package com.pi4j.io.gpio.analog;

/*-
 * #%L
 * **********************************************************************
 * ORGANIZATION  :  Pi4J
 * PROJECT       :  Pi4J :: LIBRARY  :: Java Library (CORE)
 * FILENAME      :  AnalogEvent.java
 *
 * This file is part of the Pi4J project. More information about
 * this project can be found here:  https://pi4j.com/
 * **********************************************************************
 *
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

import com.pi4j.event.Event;

/**
 * <p>AnalogEvent interface.</p>
 *
 * @author Robert Savage (<a href="http://www.savagehomeautomation.com">http://www.savagehomeautomation.com</a>)
 * @version $Id: $Id
 * @param <ANALOG_TYPE>
 * @param <CONFIG_TYPE>
 * @param <PROVIDER_TYPE>
 */
public interface AnalogEvent<ANALOG_TYPE extends Analog<ANALOG_TYPE, CONFIG_TYPE, PROVIDER_TYPE>,
        CONFIG_TYPE extends AnalogConfig<CONFIG_TYPE>,
        PROVIDER_TYPE extends AnalogProvider>
        extends Event {
    /**
     * <p>source.</p>
     *
     * @return a ANALOG_TYPE object.
     */
    ANALOG_TYPE source();
}
