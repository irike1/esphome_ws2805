import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import light
from esphome.const import CONF_ID, CONF_PIN

DEPENDENCIES = ['light']

ws2805_ns = cg.esphome_ns.namespace('ws2805')
WS2805 = ws2805_ns.class_('WS2805', light.LightOutput, cg.Component)

CONFIG_SCHEMA = light.LIGHT_SCHEMA.extend({
    cv.GenerateID(): cv.declare_id(WS2805),
    cv.Required(CONF_PIN): cv.positive_int,
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID], config[CONF_PIN])
    await cg.register_component(var, config)
    await light.register_light(var, config)
