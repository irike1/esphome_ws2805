import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import light
from esphome.const import CONF_ID, CONF_OUTPUT_ID

DEPENDENCIES = ['light']

CONF_WS2805_ID = 'ws2805_id'

ws2805_ns = cg.esphome_ns.namespace('ws2805')
WS2805 = ws2805_ns.class_('WS2805', light.LightOutput, cg.Component)

CONFIG_SCHEMA = light.LIGHT_SCHEMA.extend({
    cv.GenerateID(): cv.declare_id(WS2805),
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_WS2805_ID])
    yield cg.register_component(var, config)
    yield light.register_light(var, config)
