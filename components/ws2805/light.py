import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import light
from esphome.const import CONF_ID, CONF_OUTPUT_ID

DEPENDENCIES = ['light']

ws2805_ns = cg.esphome_ns.namespace('ws2805')
WS2805LightOutput = ws2805_ns.class_('WS2805LightOutput', light.LightOutput, cg.Component)

CONFIG_SCHEMA = light.LIGHT_SCHEMA.extend({
    cv.GenerateID(): cv.declare_id(WS2805LightOutput),
    cv.Required(CONF_OUTPUT_ID): cv.use_id(WS2805LightOutput),
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_OUTPUT_ID])
    yield cg.register_component(var, config)
    yield light.register_light(var, config)

