// -*- C++ -*-
// $Id$

# if TAO_HAS_UIOP == 1

ACE_INLINE const TAO::ObjectKey &
TAO_UIOP_Profile::object_key (void) const
{
  return this->object_key_;
}

ACE_INLINE TAO::ObjectKey *
TAO_UIOP_Profile::_key (void) const
{
  TAO::ObjectKey *key = 0;

  ACE_NEW_RETURN (key,
                  TAO::ObjectKey (this->object_key_),
                  0);

  return key;
}

#endif  /* TAO_HAS_UIOP == 1 */
